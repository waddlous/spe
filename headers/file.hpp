//File io header file
using namespace std;

//Read from setup file
void read()
{
	//???
}

//Write to output file
void writeBox(string filename, Box2D *thisbox)
{
	ofstream output;
	output.open("result/" + filename + ".txt",ios::app);
	output << left;
	output << setw(3) << framenumber << " / " << thisbox->position << " / " << thisbox->velocity << "\n";
	output.close();
}
