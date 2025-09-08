//Object(for physics) class header file
//Include libraries (and using namespace std)
using namespace std;

//Constants
Vector2 gravityV = *new Vector2(0,-16.33333333);
Vector2 nullvtr = *new Vector2(NULL,NULL);
const float gravityC = 16.33333333;
const float ballRadius = 12.095775675; //cm
const float ballMass = 0.6; //kg
const float rimRadius = 22.5; //cm
const float boardSize = 107; //cm
const float elasticity = 1;

//Pre-declaration
class Box2D;
bool collision(Box2D offense, Box2D defense);

//Simple physics affected Box object
class Box2D
{
	//Attributes
	public:
	Vector2 position; //center of the box
	Vector2 point[4] = { nullvtr }; //check documentation for specifics
	bool dynamic; //UNUSED
	float mass = ballMass; //kg
	Vector2 velocity = *new Vector2(0,0); //centimeters per second
	
	//Relative positions for points
	Vector2 zero = Vector2(1,1);
	Vector2 one = Vector2(-1,1);
	Vector2 two = Vector2(-1,-1);
	Vector2 three = Vector2(1,-1);
	float scale; //scaling

	//Constructors
	public:
	Box2D(Vector2 pos, bool dyna, float scl) : position(pos), dynamic(dyna), scale(scl)
	{
		point[0] = zero + pos;
		point[1] = one + pos;
		point[2] = two + pos;
		point[3] = three + pos;
	}
	Box2D(Vector2 *pos, bool dyna, float scl) : position(*pos), dynamic(dyna), scale(scl)
	{
		point[0] = zero + *pos;
		point[1] = one + *pos;
		point[2] = two + *pos;
		point[3] = three + *pos;
	}

	//Methods
	public:

	//Add force measured in newtons
	void addForce(Vector2 direction, float newtons)
	{
		velocity.x += (direction.norm().x * newtons / mass);
		velocity.y += (direction.norm().y * newtons / mass);
	}
	//Draw to window
	void drawBox()
	{
		drawLine(point[0],point[1]);
		drawLine(point[1],point[2]);
		drawLine(point[2],point[3]);
		drawLine(point[3],point[0]);
	}
	//Updates basically everything
	void update()
	{
		//Convert velocity to movement
		position.x = position.x + (velocity.x/60);
		position.y = position.y + (velocity.y/60);

		//Refresh scaling
		zero = *new Vector2(1,1) * scale;
		one = *new Vector2(-1,1) * scale;
		two = *new Vector2(-1,-1) * scale;
		three = *new Vector2(1,-1) * scale;

		//Absolute positions for points
		point[0] = zero + position;
		point[1] = one + position;
		point[2] = two + position;
		point[3] = three + position;

		//Draw the box
		drawBox();
	}
};

//Check collision (current position), UNUSED
bool collision(Box2D offense, Box2D defense)
{
	bool returnValue = false;
	Vector2 offvtr = nullvtr;
	Vector2 defvtr = nullvtr;
	Vector2 neutralvtr = nullvtr;
	int oPlus = 1;
	bool result[4] = { true };

	for (int i = 0; i < 4; i++)
	{
		for (int o = 0; o < 4; o++)
		{
			oPlus = o + 1;
			if (oPlus == 4) oPlus = 0;
			offvtr = getd(offense.point[i], defense.point[o]);
			defvtr = getd(defense.point[o], defense.point[oPlus]);
			if (dotProduct(offvtr, defvtr) > 0) { result[i] = false; break; }
			else result[i] = true;
		}
		
		if ((result[i]) == true) 
		{
			returnValue = true;
			break;
		}
	}
	
	return returnValue;
}

//Check collision (anticipated position)
bool newCollision(Box2D offense, Box2D defense)
{
	bool returnValue = false;

	offense.position.x = offense.position.x + (offense.velocity.x/60);
	offense.position.y = offense.position.y + (offense.velocity.y/60);
	defense.position.x = defense.position.x + (defense.velocity.x/60);
	defense.position.x = defense.position.x + (defense.velocity.y/60);
	offense.point[0] = offense.zero + offense.position;
	offense.point[1] = offense.one + offense.position;
	offense.point[2] = offense.two + offense.position;
	offense.point[3] = offense.three + offense.position;
	defense.point[0] = defense.zero + defense.position;
	defense.point[1] = defense.one + defense.position;
	defense.point[2] = defense.two + defense.position;
	defense.point[3] = defense.three + defense.position;

	Vector2 offvtr = nullvtr;
	Vector2 defvtr = nullvtr;
	Vector2 neutralvtr = nullvtr;
	int oPlus = 1;
	bool result[4] = { true };

	for (int i = 0; i < 4; i++)
	{
		for (int o = 0; o < 4; o++)
		{
			oPlus = o + 1;
			if (oPlus == 4) oPlus = 0;
			offvtr = getd(offense.point[i], defense.point[o]);
			defvtr = getd(defense.point[o], defense.point[oPlus]);
			if (dotProduct(offvtr, defvtr) > 0) { result[i] = false; break; }
			else result[i] = true;
		}
		
		if ((result[i]) == true) 
		{
			returnValue = true;
			break;
		}
	}

	return returnValue;
}
