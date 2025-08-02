//Object(for physics) class header file

//Include libraries (and using namespace std)
using namespace std;

//Global constants and variables and functions

//I'm gonna have to use A LOT of comments for this one

//Simple physics affected Box object
class Box2D
{
	//Attributes
	public:
	Vector2 position; //center of the box
	Vector2 point[4]; //check documentation for specifics
	bool dynamic; //true -> affected by physics, false -> immovable object
	float mass = 1; //IN KG
	Vector2 velocity = *new Vector2(0,0); //default: stationary
	const Vector2 zero = Vector2(100,100);
	const Vector2 one = Vector2(-100,100);
	const Vector2 two = Vector2(-100,-100);
	const Vector2 three = Vector2(100,-100);

	//Constructor (will have default points, make a function to replace it i guess)
	public:
	Box2D(Vector2 pos, bool dyna) : position(pos), dynamic(dyna)
	{
		point[0] = zero + pos;
		point[1] = one + pos;
		point[2] = two + pos;
		point[3] = three + pos;
	}
	Box2D(Vector2 *pos, bool dyna) : position(*pos), dynamic(dyna)
	{
		point[0] = zero + *pos;
		point[1] = one + *pos;
		point[2] = two + *pos;
		point[3] = three + *pos;
	}

	//Methods
	public:
	//addForce
	void addForce(Vector2 force)
	{
		velocity.x += (force.x / mass);
		velocity.y += (force.y / mass);
	}
	//draw
	void drawBox()
	{
		drawLine(point[0],point[1]);
		drawLine(point[1],point[2]);
		drawLine(point[2],point[3]);
		drawLine(point[3],point[0]);
	}
	//update
	void update()
	{
		position = position + velocity;
		point[0] = zero + position;
		point[1] = one + position;
		point[2] = two + position;
		point[3] = three + position;
		drawBox();
	}
	//real position: returns 'real' position of point
	Vector2 *rpoint(int num)
	{
		Vector2 *returnValue;
		returnValue = new Vector2(this->position + this->point[num]);
		return returnValue;
	}
};
