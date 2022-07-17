# here we define a main function
import cs50

# the main function just like other function can also take a input
def main (n):
    # n = cs50.get_int("How many times you want to meow ?")
    meow(n)

# here meow take n as an input (Notice here we still don not need to define the type )
def meow(n):
    for i in range (n):
        print("Meow~")

# Now, by the time we actually call our main function, the meow function will already have been defined.
main(4)