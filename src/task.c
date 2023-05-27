#include "task.h"
#include <stdlib.h>
#include <string.h>

Task task_new(char* name, int id, int priority, int burst){
	Task t = {
		.name = name,
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
