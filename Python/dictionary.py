# using set() - a type of data in python
words = set()

# Notice we have to design load, check , size , unload function in pset5 Speller.
# Notice that we haven’t needed a main function.

# load function
def load (dictionary):

    # We dont need to define the File type in c
    # we just use open to open a file
    file = open(dictionary, "r")

    # line will literally take each line of date and put in the varible called line
    # Notice that line is a string, but has a .rstrip function we can call.
    for line in file:

        # we use the line's function rstrip() funtion to get rid of the "\n" in each end of the line
        # and put word in the set of words using add function
        words.add(line.rstrip())

    # close the file
    file.close()
    return True

#  we need to check whether the word is in the dicitonary we loded
def check (word):

    # for case sensetivity matter we need to lower the case in word
    # by using word.lower()
    if word.lower() in words:

        return True
    else:

        return False

def size():

    # we can use the len to show we can use len to count the number of elements in our set
    return len(words)

def unlode():

    # since we dont use the malloc we do not need to free the memeory
    return True


# Python is so much easier to write and understand than c
# So pyhthon is a higher level of writting a code , where I might dont need to think at a lower level
# In python we dont need to understand what happened under the hood

# This is achieved because python itself is a programm that functions as an interpretor
# Thus Run pyhton might take much more time than Run C