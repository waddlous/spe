//Object (and camera i guess) class header file

//Include libraries (and using namespace std)
#include "vector3.hpp"
using namespace std;

//Global constants and variables


//I'm gonna have to use A LOT of comments for this one

//Camera object
class Camera
{
	//Attributes
	public:
	Vector3 position;
	Vector2 rotation;
	float fov;
	float distance; //distance to CRScreen

	//Constructor
	public:
	Camera(Vector3 pos, Vector2 rot, float angle = 60) : position(pos), rotation(rot), fov(angle) {}
	Camera(Vector3 *pos, Vector2 *rot, float angle = 60) : position(*pos), rotation(*rot), fov(angle) {} 

	//Methods (so far so good)
	public:
	//tp: teleports the camera to a location
	void tp(Vector3 *newpos)
	{
		position = *newpos;
	}
	//move: adds to the position of the camera
	void move(Vector3 *newpos)
	{
		position = position + *newpos;
	}
	//look: immediately looks in a direction
	void look(Vector2 *newrot)
	{
		rotation = *newrot;
	}
	//turn: adds to the rotation of the camera
	void turn(Vector2 *newrot)
	{
		rotation = rotation + *newrot;
	}
};

//Camera Render Screen object
class CRScreen
{
	//Attributes
	public:
	Vector3 position;
	Vector2* plane = new Vector2(LOGIC_SCREEN_W, LOGIC_SCREEN_H); //screen dimensions

	//Constructor
	public:
	CRScreen(Vector3 pos) : position(pos) {}
	CRScreen(Vector3* pos) : position(*pos) {}
	
	//Methods
	public:
	void line(Vector2* start, Vector2* end)
	{
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_RenderLine(renderer, start->x, -start->y+480, end->x, -end->y+480);
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
	}
};
