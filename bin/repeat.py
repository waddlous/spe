import sys
import os
import subprocess

argumentFirst = sys.argv[1]
argumentSecond = sys.argv[2]
for i in range(int(argumentSecond)):
    os.system(f'{argumentFirst} {i}')
