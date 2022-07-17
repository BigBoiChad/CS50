# Notice the name of the file is Csv
# if the name is the same as the csv package
# the program will not import the package but rather import itself
# thats called a circular import
import csv
from cs50 import get_string

file = open("phonebook.csv", "a")

name = get_string("Name: ")
number = get_string("Number: ")

writer = csv.writer(file)

# this function will write data in to clomn  name , number
writer.writerow([name, number])

file.close()



