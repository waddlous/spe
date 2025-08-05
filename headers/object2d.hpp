//Object(for physics) class header file

//Include libraries (and using namespace std)
using namespace std;

//Global constants and variables and functions
Vector2 gravityV = *new Vector2(0,-16.33333333);
const float gravityC = 16.33333333;

//I'm gonna have to use A LOT of comments for this one

//Simple physics affected Box object
class Box2D
{
	//Attributes
	public:
	Vector2 position; //center of the box
	Vector2 point[4]; //check documentation for specifics
	bool dynamic; //true -> affected by physics, false -> immovable object
	float mass = 0.6; //IN KG
	Vector2 velocity = *new Vector2(0,0); //default: stationary
	Vector2 zero = Vector2(12.3,12.3);
	Vector2 one = Vector2(-12.3,12.3);
	Vector2 two = Vector2(-12.3,-12.3);
	Vector2 three = Vector2(12.3,-12.3);
	float scale = 1;

	//Constructor (will have default points, make a function to replace it i guess)
	public:
	Box2D(Vector2 pos, bool dyna, float scl = 1) : position(pos), dynamic(dyna), scale(scl)
	{
		zero.x *= scale; //10,10
		zero.y *= scale;
		one.x *= scale; //-10,10
		one.y *= scale;
		two.x *= scale; //...
		two.y *= scale;
		three.x *= scale;
		three.y *= scale;
		point[0] = zero + pos;
		point[1] = one + pos;
		point[2] = two + pos;
		point[3] = three + pos;
	}
	Box2D(Vector2 *pos, bool dyna, float scl = 1) : position(*pos), dynamic(dyna)
	{
		zero.x *= scale;
		zero.y *= scale;
		one.x *= scale;
		one.y *= scale;
		two.x *= scale;
		two.y *= scale;
		three.x *= scale;
		three.y *= scale;
		point[0] = zero + *pos;
		point[1] = one + *pos;
		point[2] = two + *pos;
		point[3] = three + *pos;
	}

	//Methods
	public:
	//addForce
	void addForce(Vector2 direction, float newtons)
	{
		velocity.x += (direction.norm().x * newtons / mass);
		velocity.y += (direction.norm().y * newtons / mass);
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
		position.x = position.x + (velocity.x/60);
		position.y = position.y + (velocity.y/60);
		zero.x *= scale;
		zero.y *= scale;
		one.x *= scale;
		one.y *= scale;
		two.x *= scale;
		two.y *= scale;
		three.x *= scale;
		three.y *= scale;
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
