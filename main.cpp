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
#include"headers/basic.h"
#include"headers/vector3.h"
#include"headers/draw.h"
#include"headers/object.h"
using namespace std;

//!!!!Main Function!!!!
int main()
{
	//Initialize ("init()" from basic.h)
	if( !init() )
	{
		SDL_Log("Unable to initialize program!\n" );
	}

	//Set render draw color
	SDL_SetRenderDrawColor(renderer,255,255,255,255);

	//!!!!Main Loop!!!!
	bool quit{ false };
	while ( quit == false )
	{
		//Handle events (from basic.h)
		if ( eventHandler() == 1 )
		{
			quit = true;
		}
		
		//Random stuff (for now)
		lineMan(200,100,440,100);
		lineMan(440,100,440,340);
		lineMan(440,340,200,340);
		lineMan(200,340,200,100);
		SDL_RenderPresent(renderer);

	}

	//Closes SDL (from basic.h)
	close();
	
}
