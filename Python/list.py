scores = [72 , 73 ,33]
# Notice here we can use the python bulid-in function
# sum and len (the number of elements in scores)
print ("Average: " + str(sum(scores) / len(scores)))

from cs50 import get_int

score = []

for i in range (3):
    
    score.append(get_int("Score: "))
print(score)

from cs50 import get_string

s = get_string("before: ")
after = s.upper()
print (after)

for c in s:
    print(c.upper(), end = "")
print()
    