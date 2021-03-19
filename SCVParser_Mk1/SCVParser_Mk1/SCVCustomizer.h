#pragma once
//#include "SCVCustomizer.cpp"
class SCVCustomizer
{
private:
	char delimiterSymb;
	char newLineSymb;
	char escapingSymb;
public:

	SCVCustomizer();
 
	bool setDelimiter(char t);
	bool set_escaping_symbol(char t);
	char const tellDelimiterSymb();
	char const tellNewLineSymb();
	char const tellEscapingSymb();
};