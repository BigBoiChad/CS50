# lets reuse the same route!!
from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/", methods = ["POST", "GET"])
def index():
    if request.method == "POST":
        return render_template("greet.html", name = request.form.get("Name", "World"))
    return render_template("index.html")