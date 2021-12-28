# Marshall Copeland
# Due Date: 9/29/2021
# The program in this file is the individual work of Marshall Copeland

from flask import Flask, render_template, request
import sqlite3 as sql
app = Flask(__name__)

@app.route('/') # render home page
def home():
    return render_template('index.html')

@app.route('/addreview',methods = ['POST','GET']) # renders add review 
def add_review():
    if request.method == 'GET':
        return render_template('addReview.html') # view add review at first

    if request.method == 'POST':
        try:
            user = request.form['Username']
            restaurant = request.form['Restaurant']
            food = request.form['Food']
            service = request.form['Service']
            ambience = request.form['Ambience']
            price = request.form['Price']
            overall = request.form['Overall']
            review = request.form['Review'] # take info from the form

            with sql.connect("reviewData.db") as con: # connect to the database
                cur = con.cursor()
                cur.execute("INSERT INTO Reviews (Username,Restaurant,ReviewTime,Rating,Review) VALUES (?,?,?,?,?)",(user,restaurant,"datetime(now)",overall,review) ) # insert relevant info to the reviews table
                cur.execute("INSERT INTO Ratings (Restaurant,Food,Service,Ambience,Price,Overall) VALUES (?,?,?,?,?,?)",(restaurant,food,service,ambience,price,overall) ) # insert relevant info to the ratings table

                con.commit() # end 
                msg = "Review successfully added"
        except:
            con.rollback() # otherwise theres an error
            msg = "Error in insertion"
        
        finally:
            return render_template('addReview.html', msg = msg) # return the page
            con.close() # end the connection

@app.route('/getreview', methods = ['POST','GET']) # get review page
def get_review():
    if request.method == 'GET':
        return render_template('getReview.html') # return review page

    elif request.method == 'POST': # return the info page
        restaurant = request.form['Restaurant'] # get the restaurant name
        con = sql.connect("reviewData.db") # connect to the database
        con.row_factory = sql.Row
        cur = con.cursor()
        cur.execute("SELECT Username,Review,Rating FROM Reviews WHERE Restaurant = '%s'" % restaurant) # get relevant info
        rows = cur.fetchall()
        return render_template("showReviews.html", rows = rows, name = restaurant) # return the info page

@app.route('/showreport') # list out the top 10 restaruants
def show_report():
    con = sql.connect("reviewData.db") # connect to the database
    con.row_factory = sql.Row
    cur = con.cursor()
    cur.execute("SELECT * FROM Ratings GROUP BY Restaurant ORDER BY AVG(Overall) Desc") # order the info
    rows = cur.fetchall()
    return render_template("showReport.html",rows = rows) # return the page with the updated table

if __name__ == '__main__': # run the program
    app.run(host='0.0.0.0', debug = True)
