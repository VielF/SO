#ifndef _strdup_h_include_
#define _strdup_h_include_

#include <string.h>
#include <stdlib.h>

char* str_clone(const char* s){
	int n = strlen(s);
	char* dup = malloc(n + 1);
	memcpy(dup, s, n);
	dup[n] = 0;
	return dup;
}


#endif /* Include guard */
