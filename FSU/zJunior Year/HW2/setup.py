# Marshall Copeland
# Due Date: 9/29/2021
# The program in this file is the individual work of Marshall Copeland

import sqlite3

conn = sqlite3.connect('reviewData.db') # creates database file

conn.execute('CREATE TABLE Reviews (Username VARCHAR(40), Restaurant VARCHAR(50), ReviewTime DATETIME, Rating REAL, Review VARCHAR(500))')
print("Opened database successfully") # creates Reviews table

conn.execute('CREATE TABLE Ratings (Restaurant VARCHAR(50), Food REAL, Service REAL, Ambience REAL, Price REAL, Overall REAL)')
print("Table created sucessfully") # creates Ratings table

conn.close() # ends connection
