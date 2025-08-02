//Object(for rendering) class header file

//Include libraries (and using namespace std)
using namespace std;

//Global constants and variables and functions

//draw line
void drawLine(Vector2 *start, Vector2 *end)
{
	SDL_SetRenderDrawColor(renderer,255,138,218,255);
	SDL_RenderLine(renderer, start->x, -start->y+480, end->x, -end->y+480);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
}

void drawLine(Vector2 start, Vector2 end)
{
	SDL_SetRenderDrawColor(renderer,255,138,218,255);
	SDL_RenderLine(renderer, start.x, -start.y+480, end.x, -end.y+480);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
}
//add more if needed
