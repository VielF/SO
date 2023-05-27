#define _POSIX_C_SOURCE 200809L
#include "task.h"
#include <stdlib.h>
#include <string.h>

Task task_new(const char* name, int id, int priority, int burst){
	Task t = {
		.name = strdup(name),
		.tid = id,
		.burst = burst,
		.priority = priority,
	};
	return t;
}

void task_del(Task* t){
	if(t == NULL){ return; }
	free(t->name);
	t->name = NULL;
}
