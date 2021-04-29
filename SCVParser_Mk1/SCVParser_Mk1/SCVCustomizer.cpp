#pragma once

#include "SCVCustomizer.h"


SCVCustomizer::SCVCustomizer() : delimiterSymb(","), newLineSymb("\n"), escapingSymb("\"\"\"")
{};

bool SCVCustomizer::setDelimiter(string t)
{
	if (t == newLineSymb || t == escapingSymb)
		return false;

	delimiterSymb = t;
	return true;
};

bool SCVCustomizer::set_escaping_symbol(string t)
{
	if (t == delimiterSymb || t == newLineSymb)
		return false;

	escapingSymb = t;
	return true;
};

bool SCVCustomizer::set_newLine_symbol(string t)
{
	if (t == delimiterSymb || t == escapingSymb)
		return false;

	newLineSymb = t;
	return true;
};

//Tell Symbols
string SCVCustomizer::tellDelimiterSymb()
{
	return delimiterSymb;
}

string SCVCustomizer::tellNewLineSymb()
{
	return newLineSymb;
}

string SCVCustomizer::tellEscapingSymb()
{
	return escapingSymb;
}

// Length
int16_t SCVCustomizer::tellDelimiterSymbLength()
{
	return delimiterSymb.length();
}

int16_t SCVCustomizer::tellNewLineSymbLength()
{
	return newLineSymb.length();
}

int16_t SCVCustomizer::tellEscapingSymbLength()
{
	return escapingSymb.length();
}