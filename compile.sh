#!/bin/bash
spe=$1
if g++ main.cpp -lSDL3 -o"$spe"; then
	printf '\n'
	printf '****************Compiled successfully****************\n'
else
	printf '%%%%%%%%%%%%%%%%%%%%Errors found!%%%%%%%%%%%%%%%%%%%%\n'
fi
ls --color=auto
printf '*****************************************************\n'

