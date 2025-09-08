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

	//Magnitude
	float magn()
	{
		float returnValue = float( sqrt(x*x+y*y) );
		return returnValue;
	}
	
	//Return normalized vector
	Vector2 norm()
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
	os << setw(8) << v2.x << " " << setw(8) << v2.y;
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

//Overloading "*"
Vector2 operator*(Vector2 const& v2, float ft)
{
	Vector2 returnvalue;
	returnvalue.x = v2.x * ft;
	returnvalue.y = v2.y * ft;
	return returnvalue;
}

//Overloading "/"
Vector2 operator/(Vector2 const& v2a, Vector2 const& v2b)
{
	Vector2 returnvalue;
	returnvalue.x = v2a.x / v2b.x;
	returnvalue.y = v2a.y / v2b.y;
	return returnvalue;
}

//Overloading "=="
bool operator==(Vector2 const& v2a, Vector2 const& v2b)
{
	bool returnvalue = true;
	if (v2a.x != v2b.x) returnvalue = false;
	if (v2a.y != v2b.y) returnvalue = false;
	return returnvalue;
}

//Overloading "!="
bool operator!=(Vector2 const& v2a, Vector2 const& v2b)
{
	bool returnvalue = false;
	if (v2a.x != v2b.x) returnvalue = true;
	if (v2a.y != v2b.y) returnvalue = true;
	return returnvalue;
}

float dotProduct(Vector2 a, Vector2 b)
{
	//a•b = ax*bx + by*by
	float returnValue;
	returnValue = a.x * b.x + a.y * b.y;
	return returnValue;
}

float dotProduct(Vector2 *a, Vector2 *b)
{
	//a•b = ax*bx + by*by
	float returnValue;
	returnValue = a->x * b->x + a->y * b->y;
	return returnValue;
}

//Get distance between 2 Vectors
Vector2 getd(Vector2 a, Vector2 b)
{
	Vector2 returnValue;
	returnValue = b - a;
	return returnValue;
}
