from flask import Flask , request, render_template, redirect

app = Flask(__name__)

SPORTS = [
    "Dogeball",
    "Tennis",
    "Football",
    "Volleyball"
    ]

REGISTERANTS = {}


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


    REGISTERANTS[name] = sport

    return redirect("/registerants")


@app.route("/registerants")
def registerants():
     return render_template("registerants.html", registerants = REGISTERANTS)

