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

I just included it in the project :>  

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

### 25/07/05

Planning to use a CLI library(dabueke77 cli)  
Fixed(?) deltaTime  
Tested framerate(works okay)  
Touched up on Camera and CRScreen  
Added getd()  
Split object.hpp and render.hpp  
Still no idea about sdl3 on windows :/  

### 25/07/12

First time developing on Arch Hyprland (hooray)  
Beginning to establish a spatial system  
Made a demo geometry dash-esque spinning cube  
Used a metronome to see if deltaTime is really working  
Apparently it works...?  
Checked for memory leaks  
There seems to be none  
Not much done today  
Maybe I should figure out how to install sdl3 on windows :/  

### 25/07/23

Using cmake  
Somehow working???  
Idk I'm still doing stuff  
Uhhhhh  
It worked...?  
Wow  
This is great  
I should use cmake more often  
This means I can probably build from windows  

### 25/07/26

Testing cmake on windows  
Let's see if it works  
I tried for 2 hours.  
Windows sucks  
It fails at 97%  
oh well  
Today I began writing the intersection thing  
Gosh  
I am in so much pain  
I need to learn about vectors (officially)  
And I have to be able to put it into code  
