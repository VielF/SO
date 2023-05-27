#include "schedule.h"
#include "list.h"
#include "task.h"
#include <stdio.h>
#include <stdlib.h>

struct Scheduler {
	List tasks;
	int last_id;
};

Scheduler* sched_new(){
	Scheduler* sc = malloc(sizeof(*sc));
	sc->tasks = list_new();
	sc->last_id = 0;
	return sc;
}

void sched_run(Scheduler* sc){
	printf("FCFS\n");
}

void sched_add(Scheduler* sc, char *name, int priority, int burst){
	Task* new_task = malloc(sizeof(*new_task));
	sc->last_id += 1;
	*new_task = task_new(name, sc->last_id, priority, burst);
	list_add(&sc->tasks, new_task);
}

void sched_del(Scheduler* sc){
	if(sc == NULL){ return; }
	list_del(&sc->tasks);
	free(sc);
}
