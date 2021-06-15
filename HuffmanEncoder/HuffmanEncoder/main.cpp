#pragma once
#include "Archiver.h"

int main()
{
	Archivator arc;

	cout << "-c == code  || -d == decode " << endl;
	char ch = ' ';
	while (ch != 'c' && 'd' )
	{
		cout << "- ";
		cin >> ch;
		cout << endl;
		if (ch == 'c')
		{
			arc.archive();
			break;
		}
		if (ch == 'd')
		{
			arc.reArchive();
			break;
		}
	}
	return 0;
}