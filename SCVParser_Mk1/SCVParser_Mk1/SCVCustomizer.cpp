#pragma once

#include "SCVCustomizer.h"


SCVCustomizer::SCVCustomizer() : delimiterSymb(','), newLineSymb('\n'), escapingSymb('"')
{
};

bool SCVCustomizer::setDelimiter(char t)
{
	if (t == newLineSymb || t == escapingSymb)
		return false;

	delimiterSymb = t;
	return true;
};

bool SCVCustomizer::set_escaping_symbol(char t)
{
	if (t == delimiterSymb || t == newLineSymb)
		return false;

	escapingSymb = t;
	return true;
};

char const SCVCustomizer::tellDelimiterSymb()
{
	return delimiterSymb;
}

char const SCVCustomizer::tellEscapingSymb()
{
	return escapingSymb;
}

char const SCVCustomizer::tellNewLineSymb()
{
	return newLineSymb;
}