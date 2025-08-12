//Command-Line Interface header file

//Include libraries (and using namespace std)
using namespace std;

//Global constants and variables
string input = "";
string infirst; //명령어의 이름
string insecond; //명령의 대상
string inthird; //명령어의 수치
int sPos[2];
int o = 0;
float inx = 0;
float iny = 0;
float inz = 0;
bool quit = false;

int algorithm()
{
	o = 0;
	int returnValue = 0;

	for (int i = 0; input[i] != NULL; i++)
	{
		if (input[i] == ' ') 
		{
			sPos[o] = i; o++; 
		}
	}
	
	cout << sPos[0] << " " << sPos[1] << endl;
	return returnValue;
}

void spe_shell()
{
	cout << "[spe_shell] >>> ";
	getline(cin,input);
	algorithm();

	//프로그램 종료
	//객체 생성
	//객체의 위치값 / 속도값을 설정하는 명령어
	//객체의 위치값 / 속도값에 +-하는 명령어
	//객체 위치 / 속도 데이터 받기 명령어
	//객체 소멸 명령어
	//정지 / 재생 
	
}


