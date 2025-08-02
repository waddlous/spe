//Vector3 (and euler i guess) class header file

//Include libraries (and using namespace std)
using namespace std;

//Vector2 class
class Vector2
{
	//Attributes
	public:
	float x; float y;
	
	//Constructor
	public:
	Vector2(float X = 0, float Y = 0) : x(X), y(Y) {}

	//Methods
	public:
	float magn()
	{
		float returnValue = float( sqrt(x*x+y*y) );
		return returnValue;
	}

	Vector2 norm() //Normalize (keep direction, magnitude = 1)
	{
		Vector2* returnValue = new Vector2( this->x/this->magn(), this->y/this->magn() );
		return *returnValue;
	}


	//Friends
	friend std::ostream& operator<<(std::ostream& os, const Vector2 v2);
};

//Overloading "<<"
std::ostream& operator<<(std::ostream& os, const Vector2 v2)
{
	os << v2.x << " " << v2.y;
	return os;
}

//Overloading "+"
Vector2 operator+(Vector2 const& v2a, Vector2 const& v2b)
{
	Vector2 returnvalue;
	returnvalue.x = v2a.x + v2b.x;
	returnvalue.y = v2a.y + v2b.y;
	return returnvalue;
}

//Overloading "-"
Vector2 operator-(Vector2 const& v2a, Vector2 const& v2b)
{
	Vector2 returnvalue;
	returnvalue.x = v2a.x - v2b.x;
	returnvalue.y = v2a.y - v2b.y;
	return returnvalue;
}
