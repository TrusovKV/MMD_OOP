#pragma once
#include <iostream>
#include<vector>
#include <map>
#include <fstream>

using namespace std;
class Input_class
{
private:
	string s, testWord;
	char ch;
	bool flag;
	double counter;
	string path;
	ifstream Input_file;

	vector <string> output;
	vector<string>::iterator p;

	string::iterator pString;

	map<string, int32_t > Leter_Stack;
	map<string, int32_t >::iterator LSp;
public:
	Input_class();//
	
	map<string, int32_t > putInMap();

	string readFile();
};