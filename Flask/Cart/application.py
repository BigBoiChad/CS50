# use a SQL database
from cs50 import SQL
from flask import Flask , request, render_template, redirect, session
from flask_session import Session

app = Flask(__name__)

db = SQL("sqlite:///store.db")

app.config["SESSION_PERMANENT"] =  False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("index.html", books = books)


@app.route("/cart", methods = ["GET", "POST"])
def cart():

    if "cart" not in session:
        session["cart"] = []

    # POST (Where the user submit the forum)
    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
        return redirect ("/cart")



    # GET the added books from session
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    print(books)
    return render_template("cart.html", books = books)
