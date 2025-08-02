//Basic header file that deals with the CLI and sdl initiation stuff

//Include libraries (and using namespace std)
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<string>
#include<iostream>
#include<math.h>
#include<iomanip>
//#include"headers/cli.hpp"
using namespace std;

//Global constants and variables
constexpr int SCREEN_W{ 1280 };
constexpr int SCREEN_H{ 960 };
constexpr int LOGIC_SCREEN_W{ 640 };
constexpr int LOGIC_SCREEN_H{ 480 };
constexpr float SINGLEFRAME{ 1000 / 60 }; //16.666...ms
SDL_Window* window{ nullptr };
SDL_Renderer* renderer{ nullptr };
SDL_Event e;
Uint32 oldTime = 0;
Uint32 nowTime = 0;
Uint32 deltaTime = 0;

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
		//Create window
		window = SDL_CreateWindow( "Simple Physics Engine", SCREEN_W, SCREEN_H, 0 );
		if( window == nullptr )
		{
			SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
			success = false;
		}

		//Create renderer
		renderer = SDL_CreateRenderer( window, nullptr );
		if( renderer == nullptr )
		{
			SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
		}
		
	}

	//Does something that prevents problems
	SDL_zero(e);

	//Set logical resolution
	SDL_SetRenderLogicalPresentation(renderer, LOGIC_SCREEN_W, LOGIC_SCREEN_H, SDL_LOGICAL_PRESENTATION_STRETCH);

	//Forces out of fullscreen
	SDL_SetWindowFullscreen(window,false);

	//Friendly startup message
	cout << "Welcome to the Simple Physics Engine!\n\n";
	return success;
}

//Closes SDL stuff
void close()
{
	//Destroy window
	SDL_DestroyWindow( window );
	window = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

//Handles events like the quit event, maybe even keyboard controls idk
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

//Framerate cap (idk if it works but it probably does, also i used deltatime hehe)
void FPSCap()
{
	nowTime = SDL_GetTicks();
	deltaTime = nowTime - oldTime;
	if (deltaTime < SINGLEFRAME) SDL_Delay(SINGLEFRAME - deltaTime);
}
