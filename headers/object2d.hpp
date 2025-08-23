//Object(for physics) class header file
//Include libraries (and using namespace std)
using namespace std;

//Global constants and variables and functions
Vector2 gravityV = *new Vector2(0,-16.33333333);
Vector2 nullvtr = *new Vector2(NULL,NULL);
const float gravityC = 16.33333333; //1 프레임에 가해지는 힘
const float ballRadius = 12.095775675; //cm 공반지름
const float ballMass = 0.6; //kg 공질량
const float ballBounce = 0.8; //탄성 지수 (eg. 80% of energy retained)
const float rimRadius = 22.5; //cm 골대반지름

//I'm gonna have to use A LOT of comments for this one

//Simple physics affected Box object
class Box2D
{
	//Attributes
	public:
	Vector2 position; //center of the box
	Vector2 point[4] = { nullvtr }; //check documentation for specifics
	bool dynamic; //true -> affected by physics, false -> immovable object
	float mass = ballMass; //IN KG
	Vector2 velocity = *new Vector2(0,0); //default: stationary
	Vector2 zero = Vector2(1,1);
	Vector2 one = Vector2(-1,1);
	Vector2 two = Vector2(-1,-1);
	Vector2 three = Vector2(1,-1);
	float scale; //scaling of the object

	//Constructor
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
		//acceleration -> position
		position.x = position.x + (velocity.x/60);
		position.y = position.y + (velocity.y/60);

		//refresh scaling
		zero = *new Vector2(1,1) * *new Vector2(scale,scale);
		one = *new Vector2(-1,1) * *new Vector2(scale,scale);
		two = *new Vector2(-1,-1) * *new Vector2(scale,scale);
		three = *new Vector2(1,-1) * *new Vector2(scale,scale);
		point[0] = zero + position;
		point[1] = one + position;
		point[2] = two + position;
		point[3] = three + position;

		//draw the box
		drawBox();
	}
};

//Simple physics affected wall object
class Wall2D
{
	//Attributes
	public:
	Vector2 position; //center of the wall
	Vector2 point[2] = { nullvtr }; //check documentation for specifics
	Vector2 zero = Vector2();
	Vector2 one = Vector2();
	int direction;
	float scale; //scaling of the object

	//Constructor (will have default points, make a function to replace it i guess)
	public:
	Wall2D(Vector2 pos, int dir, float scl) : position(pos), direction(dir), scale(scl)
	{
		point[0] = zero + pos;
		point[1] = one + pos;
	}
	Wall2D(Vector2 *pos, int dir, float scl) : position(*pos), direction(dir), scale(scl)
	{
		point[0] = zero + *pos;
		point[1] = one + *pos;
	}

	//Methods
	public:
	//draw
	void drawWall()
	{
		drawLine(point[0],point[1]);
		drawLine(point[1],point[2]);
	}
	//update
	void update()
	{
		//refresh scaling
		zero = *new Vector2(1,1) * *new Vector2(scale,scale);
		one = *new Vector2(-1,1) * *new Vector2(scale,scale);
		point[0] = zero + position;
		point[1] = one + position;

		//draw the wall
		drawWall();
	}
};

bool collision(Box2D offense, Box2D defense)
{
	bool returnValue = false;
	Vector2 offvtr = nullvtr;
	Vector2 defvtr = nullvtr;
	Vector2 neutralvtr = nullvtr;
	int oPlus = 1;
	bool result[4] = { true }; //if inside, true

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
			//cout << i << "," << o << " / " << dotProduct(offvtr, defvtr) << " / " << offvtr << " / " << defvtr << endl;
		}
		
		//cout << i << " " << result[i] << endl;
		if ((result[i]) == true) 
		{
			returnValue = true;
			break;
		}
	}

	return returnValue;
}
