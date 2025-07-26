//Object(for rendering) class header file

//Include libraries (and using namespace std)
using namespace std;

//Global constants and variables and functions
Vector3 getd(Vector3* me, Vector3* you)
{
	Vector3 returnValue;
	returnValue = *me - *you;
	return returnValue;
}

//I'm gonna have to use A LOT of comments for this one

//Camera Render Screen object
class CRScreen
{
	//Attributes
	public:
	Vector3 position; //position of the screen
	Vector2* plane = new Vector2(LOGIC_SCREEN_W, LOGIC_SCREEN_H); //screen dimensions 650x480

	//Constructor
	public:
	CRScreen(Vector3 pos) : position(pos) {}
	CRScreen(Vector3 *pos) : position(*pos) {}
	
	//Methods
	public:
	void line(Vector2 *start, Vector2 *end) //this object deals with drawing
	{
		SDL_SetRenderDrawColor(renderer,255,138,218,255);
		SDL_RenderLine(renderer, start->x, -start->y+480, end->x, -end->y+480);
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
	}
};

//Camera object
class Camera
{
	//Attributes
	public:
	Vector3 position;
	Vector2 rotation;
	float fov;
	Vector3 distance; //distance to CRScreen
	CRScreen* myscreen;

	//Constructor
	public:
	Camera(Vector3 pos, Vector2 rot, float angle = 60) : position(pos), rotation(rot), fov(angle) {}
	Camera(Vector3 *pos, Vector2 *rot, float angle = 60) : position(*pos), rotation(*rot), fov(angle) {} 

	//Methods (so far so good)
	public:
	//call this once to assign the screen to this camera
	void assign(CRScreen *thisscreen)
	{
		myscreen = thisscreen;
	}
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
	void update()
	{
		distance = getd(&(this->position), &(myscreen->position));
	}
};
