//This is the main c++ file for the "Simple Physics Engine (SPE)"
//Make sure to comment your code!
//
//SPE will be a CLI program that runs natively on linux (not planning support for windows or mac)
//
//Summon and edit object data through commands
//summon(name,type,position,momentum): summons either a dynamic or static object
//delete(name): deletes a summoned object
//tp(name,position): changes the position of an object
//iforceset(name,momentum): sets the force of a dynamic object once
//iforceadd(name,momentum): adds force to a dynamic object once
//cforceset(name,momentum,time): sets the force of a dynamic object for a set amount of time
//cforceadd(name,momentum,time): adds force to a dynamic object for a set amount of time
//rule(rule,value): changes rules such as gravity
//
//Save and load from files through commands
//save: saves to a file in the 'save' directory
//load: loads to a file in the 'load' directory
//log: logs all dynamic object data until stopped
//
//Other commands
//quit: quits the program (not going to implement autosave)
//delay: waits a little

//Include headers and use namespace std
#include"headers/basic.hpp" //&& sdl, string, iostream, iomanip
//#include"headers/vector3.hpp" //this is for 3d
#include"headers/vector2.hpp" //split vector3/2 into different files
#include"headers/render2d.hpp" //render3d.hpp is for 3d
#include"headers/object2d.hpp"
//#include"headers/maths.hpp" //this is for 3d
using namespace std;

//This will just cout stuff for me every so often
void debugLoop();

//debug stuff
Box2D box(new Vector2(200,200), true);

//!!!!Main Function!!!!
int main()
{
	//Initialize
	if( !init() )
	{
		SDL_Log("Unable to initialize program!\n" );
	}

	//Set render draw color
	SDL_SetRenderDrawColor(renderer,0,0,0,255);

	//!!!!Main Loop!!!!
	bool quit = false;
	while ( quit == false )
	{
		oldTime = SDL_GetTicks(); //oldTime
		//Handle events
		if ( eventHandler() == 1 )
		{
			quit = true;
		}
		
		//Update objects

		//Debug stuff
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		debugLoop();

		//Framerate cap
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		SDL_RenderClear(renderer);
		FPSCap(); //newTime
	}
	//END OF WHILE 

	//Closes SDL
	close();
	
	//Obligatory main() return
	return 0;
}

void debugLoop()
{
	box.drawBox();
	box.addForce(*new Vector2(0.1,0.1));
	box.update();
	cout << box.position << endl;
}
