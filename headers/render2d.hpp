//Object(for rendering) class header file

using namespace std;


//Draws a pink line on the window
void drawLine(Vector2 *start, Vector2 *end)
{
	SDL_SetRenderDrawColor(renderer,255,138,218,255);
	SDL_RenderLine(renderer, start->x, -start->y+LOGIC_SCREEN_H, end->x, -end->y+LOGIC_SCREEN_H);
}

void drawLine(Vector2 start, Vector2 end)
{
	SDL_SetRenderDrawColor(renderer,255,138,218,255);
	SDL_RenderLine(renderer, start.x, -start.y+LOGIC_SCREEN_H, end.x, -end.y+LOGIC_SCREEN_H);
}
