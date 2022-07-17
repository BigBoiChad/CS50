import csv

titles = set()

with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
    # dictreader will assume the first row is the headings we use for each data
    reader = csv.DictReader(file)

    # iterate the New dictionary
    for row in reader:
        # we need to throw away the duplicate values
        # using add to append the title
        # case sensititve !!  (make all uppercase using upper())
        # trim around the edges (trim the extra space in the word) using strip()
        # it cannot clean the . etc
        titles.add(row["title"].strip().upper())

# using the sorted to sort the titles
for title in sorted(titles):
    print(title)