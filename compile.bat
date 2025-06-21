@ECHO OFF
cmake -G "MinGW Makefiles" -S . -B dist
cd dist
cmake --build .
dir
PAUSE
