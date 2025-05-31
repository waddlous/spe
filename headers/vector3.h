//Vector3 class header file

//Include libraries
#include<iostream>

class Vector3
{
	//Attributes
	public:
	float x; float y; float z;
	
	//Constructor
	public:
	Vector3(float X = 0, float Y = 0, float Z = 0) : x(X), y(Y), z(Z) {}

	//Methods
	public:

	//Friends
	friend std::ostream& operator<<(std::ostream& os, const Vector3 v3);
};

std::ostream& operator<<(std::ostream& os, const Vector3 v3)
{
	os << v3.x << " " << v3.y << " " << v3.z;
	return os;
}
