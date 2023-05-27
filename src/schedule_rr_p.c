#include "schedule.h"
#include <stdio.h>
#include <stdlib.h>

struct Scheduler {
	List task_lists[MAX_PRIORITY - MIN_PRIORITY];
	int last_id;
};


Scheduler* sched_new(){
	Scheduler* sc = malloc(sizeof(*sc));
	sc->last_id = 0;
	for(int i = 0; i < MAX_PRIORITY - MIN_PRIORITY; i++){
		sc->task_lists[i] = list_new();
	}
	return sc;
}

void rr_exec(Scheduler sc, int index) {
	ListNode* cur = sc.task_lists[index].head;
	while (cur != NULL) {
		Task* task = cur->task;

		if (task->burst > 0) {
			if (task->burst > QUANTUM) {
				run(task, QUANTUM);
				task->burst -= QUANTUM;
			}
			else {
				run(task, task->burst);
				task->burst = 0;
				printf("Task [%s] [%d] finished.\n", task->name, task->tid);
				ListNode* next = cur->next;
				list_rm(&sc.task_lists[index], task);
				cur = next;
				continue;
			}
		}

		cur = cur->next;

		if (cur == NULL) {
			cur = sc.task_lists[index].head;
		}

		if(sc.task_lists[index].len == 0){
			printf("All tasks finished.\n");
			break;
		}
	}
}

void sched_run(Scheduler* sc){
	for(int i = MAX_PRIORITY - MIN_PRIORITY -1; i >= 0; i--){
		rr_exec(*sc, i);
	}
}

void sched_remove(Scheduler* sc, Task* task){}

int clamp(int lower, int n, int upper){
    if(n < lower){
        n = lower;
    } else if (n > upper){
        n = upper;
    }
    return n;
}

void sched_add(Scheduler* sc, char *name, int priority, int burst){
	int p = clamp(MIN_PRIORITY, priority, MAX_PRIORITY);

	Task* new_task = malloc(sizeof(*new_task));
	sc->last_id += 1;
	*new_task = task_new(name, sc->last_id, p, burst);

	list_add(&sc->task_lists[p], new_task);
}

void sched_del(Scheduler* sc){
	if(sc == NULL){ return; }
	for(int i = 0; i < MAX_PRIORITY - MIN_PRIORITY; i++){
		
	}
}
