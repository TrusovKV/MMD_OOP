#include "pch.h"

class Input_class
{
private:
	string s, testWord;
	bool flag;
	double counter;
	string path;
	ifstream Input_file;

	vector <string> output;
	vector<string>::iterator p;

	map<string, double > Leter_Stack;
	map<string, double >::iterator LSp;
public:
	Input_class()
	{
		counter = 0;
		string s = "";// getString
		string test_word = "";
		string path = "d:\\GitHub\\MMDep_OOP_Autumn_2020\\MMD_OOP_Task01_Word_Counter\\MMD_OOP_Task01_Word_Counter\\The-Hobbit.txt";// filePath The-Hobbit
		Input_file.open(path);
		bool flag = Input_file.is_open(); // is file open
	};

}