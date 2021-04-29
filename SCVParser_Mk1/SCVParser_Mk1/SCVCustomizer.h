#pragma once
//#include "SCVCustomizer.cpp"
#include <stdint.h>
#include <string>
using namespace std;

class SCVCustomizer
{
private:
	string delimiterSymb;
	string newLineSymb; // DELIM FOR GETLINE
	string escapingSymb;

	int16_t delimiterSymbLength;
	int16_t newLineSymbLength;
	int16_t escapingSymbLength;
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