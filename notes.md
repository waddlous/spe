## How to install g++(MinGW) and SDL3 on Windows:

### MinGW64 Install

Get the MinGW installer (I have it on BEN 2)  
All of the defaults are suitable for this project  
Things to install:  
mingw-developer-toolkit  
mingw32-base  
mingw32-gcc-g++  
msys-base  
Apply changes  
Type 'env' in the crappy windows search  
Edit the system path to include the directory to MinGW's binaries  

### SDL3 Install

I have no idea.  

### Development Environment

"Notepad++" is recommended  
Use command line to compile source

## Developer Log:

### 25/06/07

Today I failed to install sdl3 on windows (hooray)  
I gave up. Anyways  
The framerate capping seems to be fully functional (which is rare for me)  
I also touched up on some Vector3 class stuff and added Vector2  
The 'Camera' object type has been added  
It seems to work fine too? (i am fully expecting this to break someday)  
(not really)  
sooo yea  
interesting day today :/  

### 25/06/14

Added magn() and norm()  
Beginning to implement perspective projection  
So far I have created the new "CRScreen" object  
It will write to the screen  
