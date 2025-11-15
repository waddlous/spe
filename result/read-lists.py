import os
import sys
outputFile = sys.argv[1]
inputDirectory = sys.argv[2]

returnFile = open(outputFile, "a")
for file in os.listdir(inputDirectory):
    with open(os.path.join(inputDirectory, file)) as f:
        n = 100000
        for line in f:
            if float(line.strip()) < n:
                n = float(line.strip())
        returnFile.write("\n")
        returnFile.write(str(n))
