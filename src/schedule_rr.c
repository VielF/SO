// Round Robin scheduler implementation
#include <stdio.h>
#include <stdlib.h>
#include "schedule.h"

struct Scheduler{
	List list;
	int quantum;
	int last_id;
};

Scheduler* sched_new(){
	Scheduler* sc = (Scheduler*)malloc(sizeof(Scheduler));
	sc->list = list_new();
	sc->quantum = 10;
	sc->last_id = 0;

	return sc;
}

void sched_run(Scheduler* sc){
	printf("RR run()\n");
}

void sched_add(Scheduler* sc, char *name, int priority, int burst){
	Task* new_task = malloc(sizeof(*new_task));
	sc->last_id += 1;
	*new_task = task_new(name, sc->last_id, priority, burst);

	list_add(&sc->list, new_task);
}

void sched_del(Scheduler* sc){
	printf("RR add()\n");
}
