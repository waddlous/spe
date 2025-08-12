#!/bin/bash
if g++ main.cpp -lSDL3 -o"spe"; then
	printf '************Compiled successfully************\n'
else
	printf '\nErrors found!\n'
fi
ls --color=auto
printf '\n'
