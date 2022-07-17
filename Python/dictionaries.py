import csv

# this is a dictionary type
# we use to count the number of each house
houses = {

    "Alex":0,
    "Kiki":0,
    "alex":0,
    "Brain":0,
    "Queen" :0
}


with open("phonebook.csv", "r") as file:
    # read the file intp reader
    reader = csv.reader(file)

    # ignore the first row (skip the first row) -- next(reader)
    next(reader)
    # copy each row
    for row in reader:
        # we definde the house is the first element in the row
        # that is the name
        house = row[0]
        # we make the house (name) as a index,
        # and find  the houses[name]
        # each time this house[name] will plus one
        # so when we put the name as an input the return key (output)
        # is the number of name in the reader
        houses[house] += 1


# for house in houses
# house is the " Alex"\"Kiki"\"alex“
for house in houses:
    # the house is each name
    # the houses[house] is the return key of the dictionary (hash table)
    # we the input is house (name)
    print(f"{house}: {houses[house]}")