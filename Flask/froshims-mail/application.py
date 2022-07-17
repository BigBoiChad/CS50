# use a SQL database
from cs50 import SQL
from flask import Flask , request, render_template, redirect
from flask_mail import Mail, Message
import os
import re


app = Flask(__name__)

app.config["MAIL_DEFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")
app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
app.config["MAIL_PROT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")

mail = Mail(app)





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

    Email = request.form.get("Email")
    if not Email:
        return render_template("erro.html", message = "Missing Email")


    sport = request.form.get("sport")
    if not sport:
        return render_template("erro.html", message = "Missing Sport")
    if sport not in SPORTS:
        return render_template("erro.html", message = "Wrong Sport")



    message = Message("You're Registerd!!!",  recipients = [Email])
    mail.send(message)
    return render_template("success,html")

