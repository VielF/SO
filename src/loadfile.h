#ifndef _load_h_include_
#define _load_h_include_

#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "list.h"

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
	data[size] = 0;
	return data;
}

static List parse_tasks(const char* s, int n){
	List l = list_new();

	int begin = 0;
	int cur = 0;

	while(cur < n){
		// Name
		if(s[cur] == ','){
			str_slice(s, begin, cur);
			begin = cur + 1;
		}
		// Priority

		// Burst
		n += 1;
	}
	return l;
}

#endif /* Include guard */
