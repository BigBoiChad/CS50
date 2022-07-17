import csv
from cs50 import get_string

file = open("phonebook.csv", "a")

name = get_string("Name: ")
number = get_string("Number: ")


# using with we can automatically close the file after we "a"  it
with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    # this function will write data in to clomn  name , number
    writer.writerow([name, number])
