//Basic header file that deals with the CLI and sdl initiation stuff

//Include libraries
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<string>
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<stdint.h>
#include<stdlib.h>

//Using namespace std
using namespace std;

//Size of window on screen
constexpr int SCREEN_W{ 1600 };
constexpr int SCREEN_H{ 1200 };

//Size of window used for calculations
constexpr int LOGIC_SCREEN_W{ 800 };
constexpr int LOGIC_SCREEN_H{ 600 };

//60fps time for a single frame
constexpr float SINGLEFRAME{ 1000 / 60 }; //16.666...ms

//Declare objects and variables
SDL_Window* window{ nullptr };
SDL_Renderer* renderer{ nullptr };
SDL_Event e;
Uint32 oldTime = 0;
Uint32 nowTime = 0;
Uint32 deltaTime = 0;
int framenumber = 1;
string name;

//Startup function
bool init()
{
	//Success flag
	bool success{ true };

	//Initialize SDL
	if( !SDL_Init( SDL_INIT_VIDEO ) )
	{
		SDL_Log( "SDL could not initialize! SDL error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Initialize window
		window = SDL_CreateWindow( "Simple Physics Engine", SCREEN_W, SCREEN_H, 0 );
		if( window == nullptr )
		{
			SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
			success = false;
		}

		//Initialize renderer
		renderer = SDL_CreateRenderer( window, nullptr );
		if( renderer == nullptr )
		{
			SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
		}
		
	}

	//Do something that prevents problems
	SDL_zero(e);

	//Set logical resolution
	SDL_SetRenderLogicalPresentation(renderer, LOGIC_SCREEN_W, LOGIC_SCREEN_H, SDL_LOGICAL_PRESENTATION_STRETCH);

	//Forces out of fullscreen
	SDL_SetWindowFullscreen(window,false);

	//Friendly startup message & receive output file name
	cout << "Welcome to the Simple Physics Engine!\n\n";
	cout << "Please name the output file: ";
	cin >> name;
	return success;
}

//Close SDL
void close()
{
	//Destroy window
	SDL_DestroyWindow( window );
	window = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

//Event manager
int eventHandler()
{
	//Return value
	int returnValue{ 0 };

	//Get event data
	while( SDL_PollEvent( &e ) )
	{
		//If event is quit type
		if( e.type == SDL_EVENT_QUIT )
		{
			returnValue = 1;
		}
	}
	
	return returnValue;
}

//Framerate cap using deltaTime
void FPSCap()
{
	nowTime = SDL_GetTicks();
	deltaTime = nowTime - oldTime;
	if (deltaTime < SINGLEFRAME) SDL_Delay(uint32_t(SINGLEFRAME - float(deltaTime)));
}
