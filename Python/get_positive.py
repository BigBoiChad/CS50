from cs50 import get_int

def main():
    n = get_positive()
    print(n)

# Notice in C we use a Do-While loop
# There is no Do-While loop at Python
# we can use while-True and Break to achieve the same thing
def get_positive():
    while True:
        n = get_int("Plz give me a postitive number: ")
        if n > 0:
            # this break will break out of the loop and do the next line of code (which is the return n)
            break
    # Also notice the n here; even tho the n is defined within the while loop
    # the return can still apply to n
    # becasue in python there is not scope issue
    # the n exists in the entire function
    return n

main()