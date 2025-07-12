#!/bin/bash
if g++ main.cpp -lSDL3 -o"spe"; then
	echo "Compiled successfully"
else
	echo "Errors found!"
fi
ls --color=auto
