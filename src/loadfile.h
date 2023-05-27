#ifndef _load_h_include_
#define _load_h_include_

#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "list.h"

static char* load_file(const char* path){
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
	fclose(f);
	data[size] = 0;
	return data;
}

static List parse_tasks(const char* s, int n){
	List l = list_new();
	return l;
}

#endif /* Include guard */
