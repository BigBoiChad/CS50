import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)


# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd


# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/", methods = ["POST", "GET"])
@login_required
def index():

    """Show portfolio of stocks"""
    # First we get the user_if From the session
    user_id = session.get("user_id")
    # Get the user_name , cash from the users database
    name_row = db.execute("SELECT username, cash , cash_add FROM users WHERE id = ?", user_id)
    # the return data would be a list of one element which is a dictionary
    user_name = name_row[0]["username"]
    cash = name_row[0]["cash"]
    cash_add = name_row[0]["cash_add"]
    CASH = 10000 + int(cash_add)

    if request.method == "POST":

        cash_add_n = request.form.get("cash_add")
        cash = name_row[0]["cash"] + int(cash_add_n)
        CASH = CASH + int(cash_add_n)
        cash_add = int(cash_add) + int(cash_add_n)
        db.execute("UPDATE users SET cash = ?, cash_add = ? WHERE id = ?", cash, cash_add, user_id)
        return redirect("/")


    # Select info from the the purchases data base
    owned_stocks = db.execute("SELECT symbol, shares, company_name, price, total_price FROM purchases WHERE user_id = ?", user_id)
    # create a list of stocks that will contain all the stocks the user_owned (stock name will not be repeated)
    stocks = []

    for row in owned_stocks:
        # check if the user already has the stock
        if row["symbol"] not in stocks:
            stocks.append(row["symbol"])

    # use a loop the loop over each stock user owned and recalcuate each stock's shares  and total_price
    for stock in stocks:
        # requser for the lastest price using lookup
        price = lookup(stock)["price"]
        # this share is the share for the purchases database
        share = db.execute( "SELECT shares FROM purchases WHERE symbol = ? AND user_id = ?", stock, user_id)[0]["shares"]

        total_price = price * share

        # Update the current price and the total price of that stock (price changed)
        db.execute("UPDATE purchases SET price = ?, total_price = ? WHERE symbol = ? AND user_id = ?",price, total_price, stock, user_id)

    # Select all the related data in the updated database
    # renewer the shares and total_price now requset the data from the latest database
    owned_stocks = db.execute("SELECT symbol, shares, company_name, cash, price, total_price FROM purchases WHERE user_id = ?", user_id)

    # delete the owned data base (since  we need to  update all the feild, it is better to just use a loop and delete every time)
    if db.execute("SELECT * FROM owned WHERE user_id = ?", user_id):
        # delete the owned database every time we enter the index page (so  we create it with new data that way it will automatciall become up to date)
        db.execute("DELETE FROM owned WHERE user_id = ?", user_id)

    # chose each feild in the dictionary
    for stock in stocks:
        symbol = stock
        # the list of dictionary where the user buy the stock
        # Notice before we all renewer the shares of each different stock
        # But the data is not deleted, so if the user buy apple stock four times and each time bought one stock
        # the new database will has four idenitical dictionary that has apple stock but with four share\

        owned_stock = db.execute( "SELECT symbol, shares, company_name, cash, price, total_price FROM purchases WHERE user_id = ? AND symbol = ?", user_id, stock)

        # so we need to only select for the first one (not all of them together)
        shares = owned_stock[0]["shares"]
        company_name = owned_stock[0]["company_name"]
        # here the price can be turn into usd format that is a TEXT format
        price = usd(owned_stock[0]["price"])
        # this share is used when the user buy a stock they arleady had
        # so all we need is to update that stocks share and the total price

        # this share is use to store the share user has before
        share = 0
        # normally when user buy a new stock  we just use the total price  and we turn it into a string format
        total_price = usd(owned_stock[0]["total_price"])
        # we need to keep track the total_price in a numberic format so we can make some changes
        total_price_num = owned_stock[0]["total_price"]

        db.execute("INSERT INTO owned (user_id, user_name, symbol, shares, price, total_price,total_price_num, company_name, cash) VALUES (?,?,?,?,?,?,?,?,?)",user_id, user_name, symbol, shares,  price, total_price, total_price_num, company_name, cash)
        owns = db.execute("SELECT symbol, shares, company_name, price, total_price_num, total_price FROM owned WHERE user_id = ?", user_id)

    # shows the stock profilio we can use the owned database
    owns = db.execute("SELECT symbol, shares, company_name, price, total_price_num, total_price FROM owned WHERE user_id = ?", user_id)
    # balance  is the total amount of money
    # that is the cash + profilio
    balance = cash
    # Select all the stock in the owns dictionary and add upp all the total_price_num to balance
    for own in owns:
        balance += own["total_price_num"]
    profits = 0
    profits = balance - CASH
    results = ["profit","Loss", "even"]
    if profits >0:
        result = results[0]
        print(CASH)
        ratio = int(profits/CASH * 100)
        print(ratio)
    elif profits == 0:
        result = results[2]
        ratio = 0
    else:
        result = results[1]
        ratio = int(-profits / CASH * 100)
    print(ratio)
    balance = usd(balance)
    print(result)
    return render_template("index.html",  owns = owns, cash = usd(cash), balance=balance, profits = usd(profits), ratio = ratio, result =result)




@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    user_id = session.get("user_id")
    name_row = db.execute("SELECT username, cash FROM users WHERE id = ?", user_id)
    user_name = name_row[0]["username"]
    cash = name_row[0]["cash"]

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        #Check if the symbok is vaild
        if not symbol or not shares:
            return apology ("Missing Symbol or Shares")
        #Check if the shares is valid
        if not shares.isdigit():
            return apology ("Shares MUST BE AN INTEGER")
        # if the share is indeed a integer check for postitivity
        elif int(shares) < 1:
            return apology ("Shares MUST BE AN POSITIVE")
        # look up for stock information
        info =  lookup(symbol)
        if info == None:
            return apology ("Wrong Company Symbol")

        current_price = info["price"]
        company_name = info["name"]
        total_price = float(current_price) *int(shares)
        cash = cash - total_price

        if cash < 0:
            return apology("Needs More Cash")

        db.execute("INSERT INTO historys (user_id, user_name, symbol, shares, cash, company_name, price, total_price, type) VALUES (?,?,?,?,?,?, ?,?,?)", user_id, user_name, symbol, shares, cash, company_name, usd(current_price), usd(total_price), "BUY")

        # check if the user arleady bought the stock
        if db.execute("SELECT * FROM purchases WHERE symbol = ? AND user_id = ?", symbol, user_id):
            # we can then just update the purchases database
            shares_before = db.execute("SELECT shares FROM purchases WHERE symbol = ? AND user_id = ?", symbol, user_id)[0]["shares"]
            shares  = int(shares_before) + int(shares)
            total_price = float(current_price) *int(shares)
            db.execute("UPDATE purchases SET cash = ?, total_price = ?, shares = ? WHERE symbol = ? AND user_id = ?;", cash, total_price, shares, symbol, user_id)
        else:
            db.execute("INSERT INTO purchases (user_id, user_name, symbol, shares, cash, company_name, price, total_price) VALUES (?,?,?,?,?,?, ?,?)", user_id, user_name, symbol, shares, cash, company_name, usd(current_price), total_price)

        # always update the cash in users database too
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)
        return redirect("/")



    """Buy shares of stock"""
    owned_stocks = db.execute("SELECT symbol, shares, company_name, price FROM purchases WHERE user_id = ?", user_id)
    return render_template("buy.html", cash = usd(cash), owned_stocks = owned_stocks)


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    user_id = session.get("user_id")
    name_row = db.execute("SELECT username, cash FROM users WHERE id = ?", user_id)
    user_name = name_row[0]["username"]
    cash = name_row[0]["cash"]

    historys = db.execute("SELECT * FROM historys WHERE user_id = ?", user_id)
    return render_template("history.html", historys = historys)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():

    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology ("Missing Symbol")

        info =  lookup(symbol)


        if info == None:
            return apology ("Wrong Company Symbol")
        price = info["price"]
        price = usd(price)

        return render_template("quoted.html",info = info, price = price)

    """Get stock quote."""
    return render_template("quote.html")




@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # After the user sumbited the form
    if request.method == "POST":
        # Check if the user fill out the form correctly

        username = request.form.get("username")
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        if not username:
            return apology("Missing name")
        if len(rows) != 0:
            return apology("User Name Already Exist")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not password:
            return apology("Missing Password")
        if password != confirmation:
            return apology("Two Password Does not Match")

        # Insert the data into users table

        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, generate_password_hash(password))
        return redirect("/login")

    # Get user to fill out the form
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():

    """Sell shares of stock"""
    user_id = session.get("user_id")
    name_row = db.execute("SELECT username, cash FROM users WHERE id = ?", user_id)
    user_name = name_row[0]["username"]
    cash = name_row[0]["cash"]
    owns = db.execute("SELECT symbol FROM owned WHERE user_id = ?", user_id)
    stocks = []

    for own in owns:
        stocks.append(own["symbol"])

    if request.method == "POST":

        symbol = request.form.get('symbol')
        shares = request.form.get("shares")

        if not symbol or not shares:
            return apology ("Missing Symbol or Shares")
        elif int(shares) < 1:
            return apology ("Shares MUST BE Positive")

        info =  lookup(symbol)

        if info == None:
            return apology ("Wrong Company Symbol")
        elif symbol not in stocks:
            return apology ("You Dont Have This Stock Yet")

        shares_owned = db.execute("SELECT shares FROM owned WHERE symbol = ? AND user_id = ?", symbol, user_id)[0]["shares"]

        if int(shares) > int(shares_owned) :
             return apology ("Shares Sell Is Bigger Than You Owned!")


        current_price = info["price"]
        company_name = info["name"]

        cash = float(cash)
        total_price = float(current_price) * float(shares)
        cash = cash + total_price

        db.execute("INSERT INTO historys (user_id, user_name, symbol, shares, cash, company_name, price, total_price, type) VALUES (?,?,?,?,?,?, ?,?,?)", user_id, user_name, symbol, shares, cash, company_name, usd(current_price), total_price, "SOLD")

        shares = int(shares_owned) - int(shares)

        total_price_num = float(current_price) * float(shares)
        total_price = usd(float(current_price) * float(shares))

        db.execute("INSERT INTO sell (user_id, user_name, symbol, shares, cash, company_name, price, total_price) VALUES (?,?,?,?,?,?, ?,?)", user_id, user_name, symbol, shares, cash, company_name, current_price, total_price_num)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)


        if int(shares) == 0:
            db.execute("DELETE FROM owned WHERE symbol = ? AND user_id = ?;", symbol, user_id)
            db.execute("DELETE FROM purchases WHERE symbol = ? AND user_id = ?;", symbol, user_id)
        else:

            db.execute("UPDATE owned SET cash = ?, total_price = ?, total_price_num = ?, shares = ? WHERE symbol = ? AND user_id = ?", cash, total_price, total_price_num, shares, symbol, user_id)
            db.execute("UPDATE purchases SET cash = ?, total_price = ?, shares = ? WHERE symbol = ? AND user_id = ?;", cash, total_price_num, shares, symbol, user_id)


        pur = db.execute("SELECT symbol , shares, total_price FROM purchases WHERE user_id = ?",user_id)

        return redirect("/")


    """Sell shares of stock"""
    sales = db.execute("SELECT symbol, shares, company_name, price FROM sell WHERE user_id = ?", user_id)
    owns = db.execute("SELECT symbol, shares, company_name, price, total_price_num, total_price FROM owned WHERE user_id = ?", user_id)



    return render_template("sell.html", stocks = stocks, sales = sales, owns = owns)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
