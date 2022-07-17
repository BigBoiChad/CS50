import csv

# show popularity of a title we searched
title = input("Title: ")

with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
    # dictreader will assume the first row is the headings we use for each data
    reader = csv.DictReader(file)

    counter = 0
    # iterate the New dictionary
    for row in reader:

        if title.upper().strip() == row["title"].strip().upper():
            counter += 1
print(title ,counter)
# this search has a big O of n. Not efficient