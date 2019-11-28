#include "libmx.h"

bool mx_isspace(char c) {
	bool i = false;
	if (c==' ' || c=='\t' || c=='\n' 
		|| c=='\v' || c=='\f' || c=='\r')
		i = true;
	return i; 
}
