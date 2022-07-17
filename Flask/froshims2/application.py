from flask import Flask , request, render_template

app = Flask(__name__)

SPORTS = [
    "Dogeball",
    "Tennis",
    "Football",
    "Volleyball"
    ]

@app.route("/")
def index():
    return render_template("index.html", sports = SPORTS)

@app.route("/register", methods = ["POST"])
def register():
    # we can make sure the student sign up only for the sports that are in the SPORTS list.
    if not request.form.get("Name") or request.form.get("sports") not in SPORTS:
        return render_template("failture.html")
    return render_template("success.html")