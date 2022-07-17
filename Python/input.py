x = input("X: ")
y = input("Y: ")
print(f"Hello, {x}")
# Notice here the output is not 3
# the output is 12 
# because we treat the x . y as string (even tho have only one character)
# + here function as a join function
print(x + y)