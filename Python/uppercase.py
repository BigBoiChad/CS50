from cs50 import get_string

s = get_string("before: ")
after = s.upper()
print (after)

for c in s:
    print(c.upper(), end = "")
print()
    