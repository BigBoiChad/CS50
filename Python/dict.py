from cs50 import get_string


# this is a dictionary type of data in python
# where the keys are strings of each name we want to store,
# and the value we want to associate with each key is a string of a corresponding phone number.

# Deep down this might be solved using hash table as we did in C
# For now all we know is
# we give a word , it will return a key to find the vlaue we need
people = {
    "Brain": "12345678931",
    "Alex" : "15188231315"
}

name = get_string("The name: ")

if name in people:
    # Notice here people[name]
    # inside of the [] we put a string as a index
    # Thats ok in Python and easier to find
    print(f"Number: {people[name]}")