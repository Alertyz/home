import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///todo.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
@login_required
def index():

    if request.method == "POST":

        db.execute("UPDATE list SET done = 1 WHERE user_id = ? AND list_id = ?", session["user_id"], request.form.get("id"))
        db.execute("UPDATE list SET date = CURRENT_TIMESTAMP WHERE user_id = ? AND list_id = ?", session["user_id"], request.form.get("id"))
        
        list = db.execute("SELECT * FROM list WHERE user_id = ? AND done = 0 ", session["user_id"])
            
        return render_template("index.html", list=list)

    else:

        # TODO: Display the entries in the database on index.html
        list = db.execute("SELECT * FROM list WHERE user_id = ? AND done = 0 ", session["user_id"])

        return render_template("index.html", list=list)

@app.route("/add", methods=["GET", "POST"])
@login_required
def add():
    
    if request.method == "POST":
        db.execute("INSERT INTO list (user_id, done, todo) VALUES(?, 0, ?)", session["user_id"], request.form.get("todo"))
            
        return render_template("add.html")

    else:

        return render_template("add.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    list = db.execute("SELECT * FROM list WHERE user_id = ? AND done = 1 ", session["user_id"])
    return render_template("history.html", list=list)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["user_id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Check if username is available
        if db.execute("SELECT username FROM users WHERE username = ?", request.form.get("username")) != db.execute("SELECT user_id FROM users WHERE user_id = 0"):
            return apology("username is not available", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Check if passowords match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match", 400)

        # hash password
        has = generate_password_hash(request.form.get("password"))
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", request.form.get("username"), has)

        # Remember which user has logged in
        session["user_id"] = db.execute("SELECT user_id FROM users WHERE username = ?", request.form.get("username"))[0]["user_id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")

@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")               


