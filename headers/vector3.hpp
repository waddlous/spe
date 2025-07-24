//Vector3 (and euler i guess) class header file

//Include libraries (and using namespace std)
using namespace std;

//Vector3 class
class Vector3
{
	//Attributes
	public:
	float x; float y; float z;
	
	//Constructor
	public:
	Vector3(float X = 0, float Y = 0, float Z = 0) : x(X), y(Y), z(Z) {}

	//Class의 함수는 메서드 (Method)
	public:
	float magn() //Magnitude
	{
		float returnValue = float( sqrt(x*x+y*y+z*z) );
		return returnValue;
	}
	//NOT CONSTRUCTOR 생성자가 아니다
	Vector3 norm() //Normalize (keep direction, magnitude = 1)
	{
		Vector3* returnValue = new Vector3( this->x/this->magn(), this->y/this->magn(), this->z/this->magn() );
		return *returnValue;
	}

	//Friends
	friend std::ostream& operator<<(std::ostream& os, const Vector3 v3);
};

//Overloading "<<"
std::ostream& operator<<(std::ostream& os, const Vector3 v3)
{
	os << v3.x << " " << v3.y << " " << v3.z;
	return os;
}

//Overloading "+"
Vector3 operator+(Vector3 const& v3a, Vector3 const& v3b)
{
	Vector3 returnvalue;
	returnvalue.x = v3a.x + v3b.x;
	returnvalue.y = v3a.y + v3b.y;
	returnvalue.z = v3a.z + v3b.z;
	return returnvalue;
}

//Overloading "-"
Vector3 operator-(Vector3 const& v3a, Vector3 const& v3b)
{
	Vector3 returnvalue;
	returnvalue.x = v3a.x - v3b.x;
	returnvalue.y = v3a.y - v3b.y;
	returnvalue.z = v3a.z - v3b.z;
	return returnvalue;
}

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
	//Since angles are 0 <= x < 360, remainder of 360 is vector2 if it goes over 360
	void asAngle()
	{
		x = fmod(x, float(360));
		y = fmod(y, float(360));
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
