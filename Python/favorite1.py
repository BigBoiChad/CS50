import csv

# show popularity using dictionary
titles = {}


with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
    # dictreader will assume the first row is the headings we use for each data
    reader = csv.DictReader(file)

    # iterate the New dictionary
    for row in reader:

        title = row["title"].strip().upper()
        # we need to determine whethere the key is in the dictionary
        # if not we add to the dictionary and then set its value by one
        if title not in titles:
            titles[title] = 1
        # if it indeed in the dicitionary, we increase it by one
        else:
            titles[title] += 1

# we can use the sorted function in titles (dictionary).(sorted by the titles name ,i.e the key)
# but how to sorted the value not the key?
# we can use the key argument in sorted
# the key is a function
# python can pass function which is a first class object
for title in sorted(titles):
    print(title,titles[title])
print("\n")

# the funtion we need to pass to the sorted function
# the sorted function will call this f function for every element in the dictionary
# and the return value of the f function will be used instead to determine the actucally ordering
def f(title):
    return titles[title]


for title in sorted(titles, key = f, reverse = False):
    print(title,titles[title])
print("\n")

#  using lambda to creat a anonmous function
for title in sorted(titles, key = lambda title: titles[title], reverse = True):
    print(title,titles[title])