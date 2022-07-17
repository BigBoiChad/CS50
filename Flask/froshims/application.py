from flask import Flask , request, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods = ["POST"])
def register():
    if not request.form.get("Name") or not request.form.get("sports"):
        return render_template("failture.html")
    return render_template("success.html")