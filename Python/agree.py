import cs50

s = cs50.get_string("Do you agree?")

print("\n")
# We can also compare strings directly with ==.
if s == "y" or s == "Y" or s == "Yes" or s == "yes":
    print("Agree")
elif s == "n" or s == "N" or s == "No" or s == "no":
    print("Not Agree")

print("\n")

if s.lower() in ["y", "yes"]:
    print("Agree")
elif s.lower() in ["n", "no"]:
    print("Not Agree")

print("\n")

if s.upper() in ["Y", "YES"]:
    print("Agree")
elif s.upper() in ["N", "NO"]:
    print("Not Agree")