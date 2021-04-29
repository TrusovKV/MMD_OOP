#pragma once
//#include "SCVCustomizer.cpp"
#include <stdint.h>
#include <string>
using namespace std;

class SCVCustomizer
{
private:
	string delimiterSymb;
	string escapingSymb;
	string newLineSymb; // DELIM FOR GETLINE
public:

	SCVCustomizer();
 
	bool setDelimiter(string t);
	bool set_escaping_symbol(string t);
	bool set_newLine_symbol(string t);

	string tellDelimiterSymb();
	string tellNewLineSymb();
	string tellEscapingSymb();

	int16_t  tellDelimiterSymbLength();
	int16_t  tellNewLineSymbLength();
	int16_t  tellEscapingSymbLength();


};