//Object(for physics) class header file

//Include libraries (and using namespace std)
#include "vector3.hpp"
using namespace std;

//Global constants and variables and functions

//I'm gonna have to use A LOT of comments for this one

//Simple physics affected Box object
class Box 
{
	//Attributes
	public:
	Vector3 position; //center of the box
	Vector3 point[8]; //check documentation for specifics
	bool dynamic; //true -> affected by physics, false -> immovable object

	//Constructor
	public:
	Box(Vector3 pos, bool dyna) : position(pos), dynamic(dyna) {}

	//tp: teleports the box to a location
	void tp(Vector3 *newpos)
	{
		position = *newpos;
	}
	//move: adds to the position of the box
	void move(Vector3 *newpos)
	{
		position = position + *newpos;
	}

	//Methods
	public:

};

//Simple physics affected Octahedron object
class Octa
{
	//Attributes
	public:
	Vector3 position; //center of the octahedron
	Vector3 point[6]; //check documentation for specifics
	bool dynamic; //true -> affected by physics, false -> immovable object

	//Constructor
	public:
	Octa(Vector3 pos, bool dyna) : position(pos), dynamic(dyna) {}

	//Methods (so far so good)
	public:
	//tp: teleports the octahedron to a location
	void tp(Vector3 *newpos)
	{
		position = *newpos;
	}
	//move: adds to the position of the octahedron 
	void move(Vector3 *newpos)
	{
		position = position + *newpos;
	}

};
