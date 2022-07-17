for i in range(4):
     print("?", end = "")
print()

for i in range(3):
    for i in range(3):
        print("#", end = "")
    print()

def main(n):
    mario(n)

def mario(n):
    for i in range (n, 0 ,-1):
        print (" " * (i - 1), end="")
        
        print("#" * (n + 1 - i))


main(12)
