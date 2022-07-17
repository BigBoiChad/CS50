import cs50


def main():
    changes = get_positive_float()
    # Notice we need to convert it into int
    total_times = int(cash(changes))

    print(total_times)


def get_positive_float():
    # here we use the forever loop
    while True:
        changes = cs50.get_float("Changes Owed: ")
        # until the user put in this range
        # we will keep asking them
        if changes > 0:
            # break out of the loop and then go to the next line
            # that is return n
            break
    return changes


def cash(changes):
    money = changes * 100
    if money > 25:
        q = condition(money, 25)
        money = money - q * 25
        d = condition(money, 10)
        money = money - d * 10
        n = condition(money, 5)
        money = money - n * 5
        c = condition(money, 1)
        return q + d + n + c
    elif money > 10:
        d = condition(money, 10)
        print(d)
        money = money - d * 10
        n = condition(money, 5)
        money = money - n * 5
        c = condition(money, 1)
        return d + n + c
    elif money > 5:
        n = condition(money, 5)
        money = money - n * 5
        c = condition(money, 1)
        return n + c
    else:
        return money


# this function take money and the coins_value as input
# first it will compare the two
# and find how much a type of coins we need to reduce the money as much as possible (Greedy)
def condition(money, n):
    if money >= n:
        remain = money % n
        # the times is n * times = (money - remain)
        times = (money - remain) / n
    else:
        # if the coin is bigger than the money
        # then we need zero number of this type coin
        times = 0
    return times


main()