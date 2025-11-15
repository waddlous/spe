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
#include<ctime>
//#include"headers/maths.hpp" //this is for 3d
using namespace std;

//VARIABLES
float ballDistance = 1000 - 720;
float xVelocity = 508.219;
float yVelocity = 725.812 - 8.16666;
bool randomEnabled = true;
bool nextFrame = false;

//Pre-declaration
void physics();

//Create objects
Box2D ball(new Vector2(ballDistance,100+260), true, ballRadius);
Box2D backboard(new Vector2(1000+boardSize+rimRadius,100+304.8), false, boardSize);
Box2D goalrim(new Vector2(1000,100+304.8-rimRadius), false, rimRadius);
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
int main(int argc, char *argv[])
{
	name = argv[1];
	//Initialize
	if( !init() )
	{
		SDL_Log("Unable to initialize program!\n" );
	}
	
	atexit(close_and_exit);
	
	//Random control
	srand(time(NULL));
	int xrandom = (rand() % 51);
	int yrandom = (rand() % 51);
	cout << "Random offset: " << xrandom << " " << yrandom << endl;

	//Initial object values
	if (randomEnabled == true) ball.velocity = *new Vector2(xVelocity - 25 + xrandom, yVelocity - 25 + yrandom);
	if (randomEnabled == false) ball.velocity = *new Vector2(xVelocity,yVelocity);
	
	//Output file pointer
	file.open("../result/" + name + ".txt", ios::app);
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

		//Write to output file
		//file << setw(3) << framenumber << " / " << ball.position << " / " << ball.velocity << " / " << getd(ball.position,goalCenter).magn() << "\n";
		
		//file << setw(7) << getd(ball.position,goalCenter).magn() << " / "<< ball.position << "\n";
		file << getd(ball.position,goalCenter).magn() << "\n";
		//file << ball.position << endl;

		//Update / draw objects
		if (ball.position.y <= 100) { finished = true; quit = true; }
		if (finished == false) physics();

		//Present and clear
		if (finished == false)
		{
			SDL_RenderPresent(renderer);
			SDL_SetRenderDrawColor(renderer,0,0,0,255);
			SDL_RenderClear(renderer);
		}

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
	//Collision
	if (newCollision(ball, backboard) == true)
	{
		//failed
		//ball.position = collisionOffset(ball, backboard);
		ball.addForce(*new Vector2(-ball.velocity.x,0), ((ball.velocity.x * ball.mass) + (ball.velocity.x * ball.mass * elasticity)) / 100);
	}

	//Update (includes drawing)
	SDL_SetRenderDrawColor(renderer,209,113,179,255);
	ball.update();
	SDL_SetRenderDrawColor(renderer,255,0,0,255);
	goalrim.update();
	SDL_SetRenderDrawColor(renderer,153,238,255,255);
	backboard.update();
	trail.update(&file);
	
	//non-object drawing
	SDL_SetRenderDrawColor(renderer,255,255,0,255);
	drawLine(new Vector2(1000,100+306), new Vector2(1000,100+303.6)); //center indicator
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	drawLine(new Vector2(0,100), new Vector2(1200,100)); //the ground
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	
	//Gravity
	ball.addForce(*new Vector2(0,-1), gravityC * ball.mass);
}
