// Round Robin scheduler implementation
#include <stdio.h>
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
	Task task = task_new(name, sc->last_id, priority, burst);
	sc->last_id += 1;

	list_add(&sc->list, task);
}

void sched_del(Scheduler* sc){
	printf("RR add()\n");
}
