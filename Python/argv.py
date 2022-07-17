from sys import argv

if len(argv) == 2:
    print (f"Hello,{argv[1]}")
    sys.exit(0)
else:
    sys.exit(1)

for arg in argv:
    print(arg)
    sys.exit(0)