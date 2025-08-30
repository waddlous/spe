//This is the main c++ file for the "Simple Physics Engine (SPE)"
//Make sure to comment your code!
//
//SPE will be a CLI program that runs natively on linux (not planning support for windows or mac)

//Include headers and use namespace std
#include"headers/basic.hpp" //&& sdl, string, iostream, iomanip
//#include"headers/vector3.hpp" //this is for 3d
#include"headers/vector2.hpp" //split vector3/2 into different files
#include"headers/render2d.hpp" //render3d.hpp is for 3d
#include"headers/object2d.hpp"
//#include"headers/maths.hpp" //this is for 3d
using namespace std;

//return every frame
void physics();
int framenumber = 1; //just a frame count

//바닥 y는 100px

//debug stuff
//공은 바닥(100) + 높이(255)
Box2D near(new Vector2(300,355), true, ballRadius);
Box2D mid(new Vector2(160,355), true, ballRadius);
Box2D far(new Vector2(40,355), true, ballRadius);
//백보드는 바닥(100) + 높이(305)
//Box2D goalrim(new Vector2(760,405), false, rimRadius);
Box2D backboard(new Vector2(760,405), false, 107);
	
//!!!!Main Function!!!!
int main()
{
	//Initialize
	if( !init() )
	{
		SDL_Log("Unable to initialize program!\n" );
	}
	
	//Initial object values
	near.velocity = *new Vector2(400,490);
	
	//Set render draw color
	SDL_SetRenderDrawColor(renderer,0,0,0,255);

	bool quit = false;
	//!!!!Main Loop!!!!
	while ( quit == false )
	{
		oldTime = SDL_GetTicks(); //oldTime
		//Handle events
		if ( eventHandler() == 1 )
		{
			quit = true;
		}

		//Update objects
		physics();

		//Framerate cap
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		drawLine(new Vector2(0,100), new Vector2(800,100));
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

void physics()
{
	//Gravity
	near.addForce(*new Vector2(0,-1), gravityC * near.mass);	
	//mid.addForce(*new Vector2(0,-1), gravityC * mid.mass);	
	//far.addForce(*new Vector2(0,-1), gravityC * far.mass);	
	
	//Update
	near.update();
	if (collision(near, backboard) == true)
	{
		near.addForce(*new Vector2(-near.velocity.x,0), near.velocity.magn() * elasticity);
	}
	//mid.update();
	//far.update();
	//goalrim.update();
	backboard.update();

	cout << collision(near,backboard) << " / " << framenumber << endl;

	framenumber++; 
}
