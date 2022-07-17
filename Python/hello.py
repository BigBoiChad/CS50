from cs50 import get_string, get_int

# we dont need to define the type of a varible
answer = get_string("Whats your name? ")
# this is the join fucntion
print("Hello, " + answer,)
#We can use the syntax for format strings, f"...", to plug in variables
print(f"Hello, {answer}")

counter = 0
for i in ["a", "b", "c"]:
    counter += 1
print(counter)

counter = 0
for i in range(3):
    counter += 1
print(counter)


for i in range(0, 101, 2):
    print(i)

for i in range(100, 50, -3):
    print(i)

# Condition
x = get_int("X: ")
y = get_int("Y: ")
if x < y:
    print ("X < Y")
elif x > y:
    print("X > Y")
else:
    print("X == Y")

while x < 10:
    print("Hello!")
    x += 1


