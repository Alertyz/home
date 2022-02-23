import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    result = []
    total = []
    count = 0
    symbol = db.execute("SELECT symbol FROM port WHERE user_id = ? ORDER BY symbol ASC", session["user_id"])
    cash = db.execute("SELECT shares_own, cash FROM users WHERE id = ?", session["user_id"])

    for i in range(cash[0]["shares_own"]):
        result.append(lookup(symbol[i]["symbol"]))
        total.append(result[i]["price"] * db.execute("SELECT shares_total FROM port WHERE user_id = ? ORDER BY symbol ASC",
                                                     session["user_id"])[i]["shares_total"])

        count = count + total[i]

        total[i] = usd(total[i])
        result[i]["price"] = usd(result[i]["price"])
        db.execute("UPDATE port SET name = ?, price = ?, total = ? WHERE user_id = ? AND symbol = ?",
                   result[i]["name"], result[i]["price"], total[i], session["user_id"], result[i]["symbol"])

    cash.append(usd(count + cash[0]["cash"]))
    cash[0]["cash"] = usd(cash[0]["cash"])

    return render_template("index.html", result=db.execute("SELECT * FROM port WHERE user_id = ?", session["user_id"]), cash=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        result = lookup(request.form.get("symbol"))

        if result == None:
            return apology("invalid symbol", 400)

        elif not request.form.get("shares"):
            return apology("missing shares", 400)

        elif request.form.get("shares") <= '0':
            return apology("invalid shares", 400)

        elif request.form.get("shares").isnumeric() == False:
            return apology("invalid shares", 400)

        total = float(request.form.get("shares")) * result["price"]
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        if float(cash[0]["cash"]) < total:
            return apology("can't afford", 400)

        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total, session["user_id"])
        db.execute("INSERT INTO hist (user_id, symbol, price, shares_bought) VALUES (?, ?, ?, ?)",
                   session["user_id"], result["symbol"], usd(result["price"]), request.form.get("shares"))

        if db.execute("SELECT symbol FROM port WHERE user_id = ? AND symbol = ?", session["user_id"], result["symbol"]) == db.execute("SELECT id FROM users WHERE id = 0"):
            db.execute("INSERT INTO port (user_id, symbol, shares_total) VALUES (?, ?, ?)",
                       session["user_id"], result["symbol"], request.form.get("shares"))
            db.execute("UPDATE users SET shares_own = shares_own + 1 WHERE id = ?", session["user_id"])

        else:
            db.execute("UPDATE port SET shares_total = shares_total + ? WHERE user_id = ? AND symbol = ?",
                       request.form.get("shares"), session["user_id"], result["symbol"])

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    result = db.execute("SELECT * FROM hist WHERE user_id = ? ORDER BY date ASC", session["user_id"])
    return render_template("history.html", result=result)


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
    """Get stock quote."""
    if request.method == "POST":

        result = lookup(request.form.get("symbol"))

        if result == None:
            return apology("invalid symbol", 400)

        result["price"] = usd(result["price"])

        return render_template("quote.html", result=result)

    else:
        return render_template("quote.html", result="0")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Check if username is available
        if db.execute("SELECT username FROM users WHERE username = ?", request.form.get("username")) != db.execute("SELECT id FROM users WHERE id = 0"):
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
        session["user_id"] = db.execute("SELECT id FROM users WHERE username = ?", request.form.get("username"))[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure symbol was submitted
        if request.form.get("symbol") == None:
            return apology("missing symbol", 400)

        # Ensure shares was submitted
        elif not request.form.get("shares"):
            return apology("missing shares", 400)

        # Ensure shares is bigger than 0
        elif request.form.get("shares") <= '0':
            return apology("invalid shares", 400)

        # Ensure shares is numeric
        elif request.form.get("shares").isnumeric() == False:
            return apology("invalid shares", 400)

        # Total shares that user posses
        ST = db.execute("SELECT shares_total FROM port WHERE user_id = ? AND symbol = ?",
                        session["user_id"], request.form.get("symbol"))

        # Ensure that the user has enough shares
        if ST[0]["shares_total"] < int(request.form.get("shares")):
            return apology("too many shares", 400)

        # Price
        price = lookup(request.form.get("symbol"))

        # Write in history that the user has sold a share
        db.execute("INSERT INTO hist (user_id, symbol, price, shares_bought) VALUES (?, ?, ?, -?)",
                   session["user_id"], request.form.get("symbol"), usd(price["price"]), request.form.get("shares"))

        # If the user sell all his shares from that symbol
        if (ST[0]["shares_total"] - int(request.form.get("shares"))) == 0:
            db.execute("DELETE FROM port WHERE user_id = ? AND symbol = ?", session["user_id"], request.form.get("symbol"))
            price["price"] = price["price"] * int(request.form.get("shares"))
            db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", price["price"], session["user_id"])
            db.execute("UPDATE users SET shares_own = shares_own - 1 WHERE id = ?", session["user_id"])

        # If the user only sell a portion of the shares from that symbol
        else:
            db.execute("UPDATE port SET shares_total = shares_total - ? WHERE user_id = ? AND symbol = ?",
                       request.form.get("shares"), session["user_id"], request.form.get("symbol"))
            price["price"] = price["price"] * int(request.form.get("shares"))
            db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", price["price"], session["user_id"])

        # Return to index page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:

        # List of symbols
        result = db.execute("SELECT symbol FROM port WHERE user_id = ? ORDER BY symbol ASC", session["user_id"])

        # Show sell temaplate
        return render_template("sell.html", result=result)
