#!/bin/bash
if g++ main.cpp -lSDL3 -o"spe"; then
	printf '************\nCompiled successfully\n************\n'
else
	printf '\nErrors found!\n'
fi
ls --color=auto
printf '\n'
