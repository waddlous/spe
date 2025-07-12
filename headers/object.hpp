//Object(for physics) class header file

//Include libraries (and using namespace std)
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

	//Constructor (will have default points, make a function to replace it i guess)
	public:
	Box(Vector3 pos, bool dyna) : position(pos), dynamic(dyna)
	{
		point[0] = (-1,-1,-1);
		point[1] = (1,-1,-1);
		point[2] = (1,-1,1);
		point[3] = (-1,-1,1);
		point[4] = (-1,1,-1);
		point[5] = (1,1,-1);
		point[6] = (1,1,1);
		point[7] = (-1,1,1);
	}
	Box(Vector3 *pos, bool dyna) : position(*pos), dynamic(dyna)
	{
		point[0] = (-1,-1,-1);
		point[1] = (1,-1,-1);
		point[2] = (1,-1,1);
		point[3] = (-1,-1,1);
		point[4] = (-1,1,-1);
		point[5] = (1,1,-1);
		point[6] = (1,1,1);
		point[7] = (-1,1,1);
	}

	//Methods
	public:
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
	//real position: returns 'real' position of point
	Vector3 *rpoint(int num)
	{
		Vector3 *returnValue;
		returnValue = new Vector3(this->position + this->point[num]);
		return returnValue;
	}

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
