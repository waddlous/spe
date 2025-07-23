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
#include"headers/vector3.hpp"
#include"headers/object.hpp"
#include"headers/render.hpp"
using namespace std;

//This will just cout stuff for me every so often
void debugLoop();

//Create basic objects
Camera cam(new Vector3, new Vector2);
CRScreen screen(new Vector3(0,0,100));
Box boxObject(new Vector3(100,100,100), false);
Vector2 first(100,100);
Vector2 second(100,200);
Vector2 third(200,200);
Vector2 fourth(200,100);

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

	cam.assign(&screen);

	//!!!!Main Loop!!!!
	bool quit{ false };
	while ( quit == false )
	{
		//Handle events
		if ( eventHandler() == 1 )
		{
			quit = true;
		}
		
		//Update objects
		cam.update();

		//Debug stuff
		debugLoop();
		first = first + *(new Vector2(0,1));
		second = second + *(new Vector2(1,0));
		third = third + *(new Vector2(0,-1));
		fourth = fourth + *(new Vector2(-1,0));
		if (first.y > 200) first = *(new Vector2(100,100));
		if (second.x > 200) second = *(new Vector2(100,200));
		if (third.y < 100) third = *(new Vector2(200,200));
		if (fourth.x < 100) fourth = *(new Vector2(200,100));

		//Framerate cap
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		SDL_RenderClear(renderer);
		FPSCap();

	}

	//Closes SDL
	close();
	
}

void debugLoop()
{
	screen.line(&first,&second);
	screen.line(&second,&third);
	screen.line(&third,&fourth);
	screen.line(&fourth,&first);
}
