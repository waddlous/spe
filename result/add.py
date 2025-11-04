import sys

number = 0.0
count = 0
with open(sys.argv[1],"r") as file:
    while True:
        line = file.readline()
        print(line)
        if not line.strip():
            break
        number += float(line.strip())
        count += 1
print(number)
print(count)
print(number / count)
