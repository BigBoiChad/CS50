from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")


# the defualt methods is get.
@app.route("/greet", methods = ["POST"])
def greet():
    # when change the method to post we need to use request.form.get NOT request.args.get
    return render_template("greet.html", name=request.form.get("Name", "world"))
