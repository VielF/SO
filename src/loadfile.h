#ifndef _load_h_include_
#define _load_h_include_

#include <stdio.h>
#include <stdlib.h>

static char* loadfile(const char* path){
	FILE* f = fopen(path, "r");
	char* data = NULL;
	int start, end, size;
	fseek(f, 0, SEEK_END);
	end = ftell(f);
	rewind(f);
	start = ftell(f);
	size = end - start;
	data = malloc(size + 1);
	fread(data, 1, size, f);
	data[size] = 0;
	return data;
}

#endif /* Include guard */
