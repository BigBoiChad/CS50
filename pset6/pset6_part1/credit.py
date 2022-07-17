import cs50

# I use a list of string repersent the credit card number
# using index in a list to achieve the lunh alogrizm


def main():

    card_number = get_number()

    # if the card number satify the luhn algorizm
    # luhn() will return True
    if luhn(card_number):
        # Now we can find out the what type of credit card this is
        check_type(card_number)
    else:
        print("INVALID")


# conver the string (user typed) in to a list of strings
def get_number():

    # n here is used to count the the number of character in [0 ~ 9]
    # which will then compare the length of string to determine whether this string is completely numberic (still string type)
    n = 0
    # this is the new list that store the card_number
    num_list = []
    # make sure the card_number are all numeric
    while True:
        card = cs50.get_string("Card Number: ")
        # iterate all the elements in card (character)
        for i in range(len(card)):
            if card[i] in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                n += 1
        if n == len(card):
            break

    # put every character element in card string into a list
    for s in card:
        num_list.append(s)
    return num_list


def luhn(card_number):

    # the even index (the one need to be doubled)
    even_index_number = []
    odd_index_number = []
    even_sum = 0
    odd_sum = 0

    if len(card_number) > 16 or len(card_number) < 13:
        return False

    else:
        # from the second-last number each time - 2
        # Notice the index need to start at len(card) - 2
        # and index 0 needs to be counted
        for i in range(len(card_number) - 2, -1, -2):

            even_index_number.append(int(card_number[i]))

            odd_index_number.append(int(card_number[i + 1]))
            # this is a conor case where the first string is noexist
            # i == 1, cannot  - 2  and then the loop ended
            # here to fix that
            if i == 1:
                odd_index_number.append(int(card_number[i - 1]))

        # l here is make sure j loop exactly all the orginal elements in even_index_number
        l = len(even_index_number)
        for j in range(l):

            # we multiply by 2
            even_index_number[j] = even_index_number[j] * 2

            # if the number is bigger than 10  lets say 15
            # we need to spilt this number into 1 and 5
            # first we change 15 % 10 = 5 as the number in the index
            # then we add 1 at  the end of the list
            # the length of the list then changed
            # thats why I use l to lock the original length
            if even_index_number[j] >= 10:
                even_index_number[j] = even_index_number[j] % 10
                even_index_number.append(1)

        for m in even_index_number:
            even_sum += m

        for n in odd_index_number:
            odd_sum += n

        total_sum = even_sum + odd_sum

        print(total_sum)

        if (total_sum % 10) == 0:
            return True
        else:
            return False


def check_type(card_number):

    # this Express is a list of list
    # this is used to determine where a list is in the Express list using in function
    Express = [['3', '4'], ['3', '7']]
    # Notice here card_number [] is a string number not a int
    # so when we compare it with number we need to convert it into a int
    if 12 < len(card_number) < 17 and int(card_number[0]) == 4:
        print("VISA")

    # here card_number[0:2] means we cut this list in a piece that contain [card[0], card[1]]
    # then we use in to see whether this two elements are in the Express list
    elif card_number[0:2] in Express and len(card_number) == 15:
        print("AMEX")

    elif int(card_number[0]) == 5 and 0 < int(card_number[1]) < 6 and len(card_number) == 16:
        print("MASTERCARD")


main()