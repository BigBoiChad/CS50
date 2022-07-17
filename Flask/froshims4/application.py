# use a SQL database
from cs50 import SQL
from flask import Flask , request, render_template, redirect

app = Flask(__name__)

SPORTS = [
    "Dogeball",
    "Tennis",
    "Football",
    "Volleyball"
    ]

db = SQL("sqlite:///froshims.db")


@app.route("/")
def index():
    return render_template("index.html", sports = SPORTS)


@app.route("/register", methods = ["POST"])
def register():

    name = request.form.get("Name")
    if not name:
        return render_template("erro.html", message = "Missing Name")


    sport = request.form.get("sport")
    if not sport:
        return render_template("erro.html", message = "Missing Sport")
    if sport not in SPORTS:
        return render_template("erro.html", message = "Wrong Sport")


    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)

    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants = registrants)

