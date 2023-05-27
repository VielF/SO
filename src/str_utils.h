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

static char* str_slice(const char* s, int begin, int end){
	if(begin >= end){ return NULL; }
	int size = end - begin;
	char* sl = malloc(size + 1);
	for(int i = begin; i < end; i += 1){
		sl[i] = s[i];
	}
	sl[size] = 0;
	return sl;
}

#endif /* Include guard */
