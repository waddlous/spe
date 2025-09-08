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
#include"headers/file.hpp"
//#include"headers/maths.hpp" //this is for 3d
using namespace std;

//Pre-declaration
void physics();

//Create objects
Box2D ball(new Vector2(100+200,100+255), true, ballRadius);
Box2D backboard(new Vector2(100+660+boardSize+rimRadius,100+304.8), false, boardSize);
Box2D goalrim(new Vector2(100+660,100+304.8-rimRadius), false, rimRadius);

/*!!!!Main Function!!!!*/
int main()
{
	//Initialize
	if( !init() )
	{
		SDL_Log("Unable to initialize program!\n" );
	}
	
	//Initial object values
	ball.velocity = *new Vector2(400,690);
	
	//Create quit flag for main loop
	bool quit = false;

	/*!!!!Main Loop!!!!*/
	while ( quit == false )
	{
		oldTime = SDL_GetTicks(); //set oldTime

		//Event manager
		if ( eventHandler() == 1 )
		{
			quit = true;
		}

		//Update / draw objects
		physics();

		//Draw everything else, present and clear
		drawLine(new Vector2(0,100), new Vector2(800,100)); //floor
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		SDL_RenderClear(renderer);

		//Write to output file
		writeBox(name,&ball);

		//Increase frame count
		framenumber++;

		//Framerate limiter using deltaTime
		FPSCap(); //set newTime
	}
	/*END OF MAIN LOOP*/

	//Close SDL
	close();
	
	//Obligatory main() return
	return 0;
}

void physics()
{
	//Gravity
	ball.addForce(*new Vector2(0,-1), gravityC * ball.mass);
	
	//Update (includes drawing)
	ball.update();
	goalrim.update();
	backboard.update();

	//Collision
	if (newCollision(ball, backboard) == true) //floor
	{
		ball.addForce(*new Vector2(-ball.velocity.x,0), 2 * ball.velocity.x * ball.mass * elasticity);
	}
}
