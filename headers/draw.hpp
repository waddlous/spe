//Rendering header file that draws to the window

//Include libraries (and using namespace std)
using namespace std;

//Global constants and variables

//Draw line function
void lineMan(float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0)
{
	SDL_RenderLine(renderer,x1,y1,x2,y2);
}
