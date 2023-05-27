// Round Robin scheduler implementation

#include <stdio.h>
#include "schedule.h"

Scheduler* sched_new(){
	return NULL;
}

void sched_run(Scheduler* sc){
	printf("RR\n");
}

void sched_add(Scheduler* sc, char *name, int priority, int burst){}
