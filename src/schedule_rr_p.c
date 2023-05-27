#include "schedule.h"
#include <stdio.h>

Scheduler* sched_new(){
	return NULL;
}

void sched_run(Scheduler* sc){
	printf("RR priority\n");
}

void sched_add(Scheduler* sc, char *name, int priority, int burst){}

void sched_del(Scheduler* sc){}
