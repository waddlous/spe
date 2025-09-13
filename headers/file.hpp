//File io header file
using namespace std;

//Read from setup file
void read()
{
	//???
}

ofstream *output;

//Write to output file
void writeBox(Box2D *thisbox)
{
	*output << setw(3) << framenumber << " / " << thisbox->position << " / " << thisbox->velocity << " / " << getd(thisbox->position,goalCenter).magn() << "\n";
}
