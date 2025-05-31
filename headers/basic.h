//Basic header file that deals with the CLI and sdl initiation stuff

//Include libraries (and using namespace std)
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<string>
#include<iostream>
using namespace std;

//Global constants and variables
constexpr int screenWidth{ 1280 };
constexpr int screenHeight{ 960 };
SDL_Window* window{ nullptr };
SDL_Renderer* renderer{ nullptr };
SDL_Event e;
/* i want to put SDL_zero( e ); here but i have to initialize sdl first */

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
		window = SDL_CreateWindow( "Simple Physics Engine", screenWidth, screenHeight, 0 );
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
	SDL_SetRenderLogicalPresentation(renderer, 640, 480, SDL_LOGICAL_PRESENTATION_STRETCH);

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
	int ret{ 0 };

	//Get event data
	while( SDL_PollEvent( &e ) )
	{
		//If event is quit type
		if( e.type == SDL_EVENT_QUIT )
		{
			ret = 1;
		}
	}
	
	return ret;
}
