import cs50


def main():
    height = get_positive_int()
    mario(height)


def get_positive_int():
    # here we use the forever loop
    while True:
        n = cs50.get_int("Height: ")
        # until the user put in this range
        # we will keep asking them
        if 0 < n < 9:
            # break out of the loop and then go to the next line
            # that is return n
            break
    return n


def mario(n):

    for i in range(n):
        # Notice i start from zero
        # we first print (n - 1) number of space
        # and then after the space
        # for the first line we print a #
        # and so on
        print(" " * (n - (i+1)), end="")
        print("#" * (i + 1))


main()