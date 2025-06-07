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

	//Constructor
	public:
	Camera(Vector3 pos, Vector2 rot) : position(pos), rotation(rot) {}
	Camera(Vector3 *pos, Vector2 *rot) : position(*pos), rotation(*rot) {} 

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
	//turn: adds to the rotatin of the camera
	void turn(Vector2 *newrot)
	{
		rotation = rotation + *newrot;
	}
};
