#include <Windows.h>
#include <iostream>
#include <string>

#include "MyArchr.h"
using namespace std;

int main() //
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //Set encoding

	string adres = "D:\\text\\voina_i_mir_first_tom.txt";
	string final_name = "my_archive.txt";
	char action;

	cout << "Do you want pack(P) or unpack(u)?" << endl;
	cin >> action;

	myArchivator arch(adres, final_name);

	if (action == 'P') {
		// Packing //

		arch.readTxt();
		arch.BuildTree();
		arch.HaffmansCode();
		arch.writeToTxt();
	}
	else if (action == 'u') {
		// Unpacking //
		arch.GetInfo();
		arch.UnPack();
	}
	else {
		cout << "Please, try again" << endl;
	}

}