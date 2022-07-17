# https://cs50.harvard.edu/x/2021/psets/6/dna/
from sys import argv
import cs50
import csv


def main():

    # find out the users input
    if len(argv) != 3:
        print("Erro 1")
        sys.exit(1)

    # we need to read the database (argv[1]
    id_dict = read_file(argv[1])

    # this function checks a person's DNA
    # and match it with the database we have (a list of dictionaries)
    # and return a list of names that match the result
    name_list = check_id(argv[2], id_dict)

    # this is to see how many pairs of STR in the database
    # -1 is to deleted the name
    length = len(id_dict[0]) - 1

    # we use match function to further select the result
    # it take the name_list and the length of database as input
    # and output a single name or "No Match"
    result = match(name_list, length)

    print(result)


# this function is used to read the database and output a list of dictionaies
# which store data
def read_file(csv_file):
    # id_dict is a list (where each element is a dictionary)
    id_dict = []

    # using with open () as file to read the data into a file
    with open(csv_file, "r") as file:
        # csv.DictReader() will read the file into a dictionary type !!!
        reader = csv.DictReader(file)

        # we make every row in reader as a single dictionary that looks like this
        # {'name': 'Albus', 'AGATC': '15', 'TTTTTTCT': '49', 'AATG': '38', 'TCTAG': '5', 'GATA': '14', 'TATC': '44', 'GAAA': '14', 'TCTG': '12'},
        # and then store (append) this dictionary into the list
        for row in reader:
            id_dict.append(row)

    # return the list of dictionaries that contains name and other information
    return id_dict


def check_id(dna, id_dict):

    # first we need to caculate the STR "AGATC" etc in the person's DNA
    # we use dictionary to set all the STR's key to zero
    # if we find one, we will incerese the key by one
    strs = {
        "AGATC": 0,
        "TTTTTTCT": 0,
        "AATG": 0,
        "TCTAG": 0,
        "GATA": 0,
        "TATC": 0,
        "GAAA": 0,
        "TCTG": 0
    }

    # read the person's dna in to a file
    with open(dna, "r") as file:
        # Notcie here we just use a reader function
        # so the reader is not a dictionary type
        # rather a string type
        reader = csv.reader(file)
        # we creat a string that will store that readers first element
        # which is the entire row

        for row in reader:
            # reader here only has one row
            # a single string that contain the information as ["TCCTG ......"]
            # this row is a list that only has one element
            # we assign this element to be the id_str string
            # Notice here the id_str is a string
            # the string can also use [] to find a sing character
            id_str = row[0]

    # using tabulate function to tabulate each key in a certain strs
    # the return value of tabulate is the time of a string ("AGATC") in the person's DNA
    # we then update the key of "AGATC" into the strs dictionary
    strs["AGATC"] = tabulate("AGATC", id_str)
    strs["TTTTTTCT"] = tabulate("TTTTTTCT", id_str)
    strs["AATG"] = tabulate("AATG", id_str)
    strs["TCTAG"] = tabulate("TCTAG", id_str)
    strs["GATA"] = tabulate("GATA", id_str)
    strs["TATC"] = tabulate("TATC", id_str)
    strs["GAAA"] = tabulate("GAAA", id_str)
    strs["TCTG"] = tabulate("TCTG", id_str)

    # we then compare each string's keys with that in the database
    # and find out the matching name
    # we creat a name_list that will stroe the matches with the database
    name_list = []
    # id_dict is a list of len(id_dict) elements
    # for each elements it is a dictionary that contains information
    #{'name': 'Albus', 'AGATC': '15', 'TTTTTTCT': '49', 'AATG': '38', 'TCTAG': '5', 'GATA': '14', 'TATC': '44', 'GAAA': '14', 'TCTG': '12'}
    # so we need to iterate len(id_dict) times
    # for each time (each elements\ each dictionary)
    # we need to go inside of that dictionary and seach for a match for every string
    # using a funcion called check()
    for i in range(len(id_dict)):

        # this check funciton take the database \ and the strs dictionary and a string and a i number (i is the ith element in id_dict list)
        # as input and output a name
        name_list.append(check(strs, id_dict, "AGATC", i))
        name_list.append(check(strs, id_dict, "TTTTTTCT", i))
        name_list.append(check(strs, id_dict, "AATG", i))
        name_list.append(check(strs, id_dict, "TCTAG", i))
        name_list.append(check(strs, id_dict, "GATA", i))
        name_list.append(check(strs, id_dict, "TATC", i))
        name_list.append(check(strs, id_dict, "GAAA", i))
        name_list.append(check(strs, id_dict, "TCTG", i))

    # we then delete all the 1 (erro or no match) in the name list
    while 1 in name_list:
        name_list.remove(1)
    # now we have a name_list that has all the matching names
    return name_list


def check(strs, id_dict, string, i):

    # check for cornor case
    # if the string is not in the database
    # then return a numer 1 which indicates a erro
    if string not in id_dict[i]:
        return 1
    # else
    # we use string as index and put it in strs dictionary
    # we find the keys (the max times of the string in person's DNA)
    # we need to compare that with the dictionary
    # we need first put i as index in the id_dict
    # to loacte a single dictionary  like
    # {'name': 'Albus', 'AGATC': '15', 'TTTTTTCT': '49', 'AATG': '38',...,}
    # and put string ("AGATC")as index , we can find the times of string in database
    # if the two are the same
    # we return this ith dictionary's name
    # id_dict[i]["name"]
    if str(strs[string]) == id_dict[i][string]:

        return id_dict[i]["name"]
    # if not , return 1
    # we move on to the i + 1 dicitonary
    else:
        return 1


# take a string and the person's dna (string) and compare
def tabulate(string, id_str):

    # we set the index to 1
    # to find out whether a string * 1 in the person's dna (a long string)
    index = 1

    # if the string is 4 character
    # then we need to only check for maxmims len(id_str) / 4 times
    # this can be achieved by using the range(0 , len(id_str), 4) function
    # meaning the index can only lower or equal to len(id_str) / 4
    # this seniaro means the dna only have this string
    for i in range(0, len(id_str), len(string)):
        # first find out if the string * 1 inside of the person's dna
        if string * index in id_str:
            # if it is we increase index by one
            # and check again
            index += 1
        # if when the index = 8, doesnt not in the id_str
        # means the the dna can only have 7 * string inside (that 7 string is consequtative)
        # we need to update the index to 7 and quit the loop
        else:
            index = index - 1
            # it is important to quit the loop
            # because there is not point to change the index
            # the max index is found
            break
    # we then return the max index (times)
    return index


# for the mathcing funciton we need to make sure the match name matchs all the STR keys
def match(name_list, length):
    # first we creat a list
    # this is to store the times of a certain name in a list
    matches = {}
    # we defind the max_key (name that appers the most) to None
    max_key = None
    # we itrate each name in the list
    for name in name_list:
        # if the name is not appears in the dictionary we just define
        if name not in matches:
            # calculate to count of that name
            count = name_list.count(name)

            # we update the key in that dictionary
            matches[name] = count
            # if the count is bigger than the dicionary's max_key's count
            if count > matches.get(max_key, 0):
                # change the name to the name that has the count
                max_key = name
    # Now  we have the max_key name
    # now we need to find that name that its time is equal to the length (the pairs of str in the database)
    if name_list.count(max_key) < length:
        return "No Match"
    else:
        return max_key


main()