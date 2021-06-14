#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include "Arch.h"
#include <ctime>
using namespace std;

int main()
{
	string adres = "D:\\GitHub\\MMD_OOP\\HuffmanEncoder\\test.txt";
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