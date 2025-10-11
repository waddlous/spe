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
#include<ctime>
//#include"headers/maths.hpp" //this is for 3d
using namespace std;

//Pre-declaration
void physics();

//Create objects
Box2D ball(new Vector2(100+200,100+255), true, ballRadius);
Box2D backboard(new Vector2(100+660+boardSize+rimRadius,100+304.8), false, boardSize);
Box2D goalrim(new Vector2(100+660,100+304.8-rimRadius), false, rimRadius);
Trailer trail(&ball);

//Open file
ofstream file;

//Exit function
void close_and_exit()
{
	//Close SDL (& file)
	file.close();	
	close();
}

/*!!!!Main Function!!!!*/
int main()
{
	//Initialize
	if( !init() )
	{
		SDL_Log("Unable to initialize program!\n" );
	}
	
	atexit(close_and_exit);
	
	//Random control
	srand(time(NULL));
	int xrandom = (rand() % 101);
	int yrandom = (rand() % 101);
	cout << "Random offset: " << xrandom << " " << yrandom << endl;

	//Initial object values
	ball.velocity = *new Vector2(370 - 50 + xrandom,690 - 50 + yrandom);
	
	//Output file pointer
	file.open("result/" + name + ".txt", ios::app);
	file << left;
	
	//Create quit flag for main loop
	bool quit = false;

	//Create finish(?) flag for physics
	bool finished = false;

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
		if (ball.position.y <= 100) finished = true;
		if (finished == false) physics();

		//Draw everything else, present and clear
		drawLine(new Vector2(0,100), new Vector2(800,100)); //the ground
		if (finished == false)
		{
			SDL_RenderPresent(renderer);
			SDL_SetRenderDrawColor(renderer,0,0,0,255);
			SDL_RenderClear(renderer);
		}

		//Write to output file
		file << setw(3) << framenumber << " / " << ball.position << " / " << ball.velocity << " / " << getd(ball.position,goalCenter).magn() << "\n";

		//Increase frame count
		framenumber++;

		//Framerate limiter using deltaTime
		FPSCap(); //set newTime
	}
	/*END OF MAIN LOOP*/



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
	trail.update();

	//Collision
	if (newCollision(ball, backboard) == true) //floor
	{
		ball.addForce(*new Vector2(-ball.velocity.x,0), 2 * ball.velocity.x * ball.mass * elasticity);
	}
}
