#pragma once
#include <ctime>
#include "Archiver.h"

int main()
{
	time_t start, end;
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
			time(&start);
			arc.archive();
			time(&end);
			break;
		}
		if (ch == 'd')
		{
			time(&start);
			arc.reArchive();
			time(&end);
			break;
		}
	}
	cout << difftime(end, start) << endl;
	return 0;
}