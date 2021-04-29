#pragma once
//#include "SCVCustomizer.cpp"
#include <stdint.h>

class SCVCustomizer
{
private:
	char delimiterSymb;
	char newLineSymb; // DELIM FOR GETLINE
	char escapingSymb;
public:

	SCVCustomizer();
 
	bool setDelimiter(char t);
	bool set_escaping_symbol(char t);
	bool set_newLine_symbol(char t);

	char const tellDelimiterSymb();
	char const tellNewLineSymb();
	char const tellEscapingSymb();

	int16_t  tellDelimiterSymbLength();
	int16_t  tellNewLineSymbLength();
	int16_t tellEscapingSymbLength();

};