/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedule.h"

#define SIZE	100

int main(int argc, char *argv[]){
	if(argc < 2){ return 1; }
	FILE *in;
	char *temp;
	char task[SIZE];
	Scheduler* sc = sched_new();

	char *name;
	int priority;
	int burst;

	in = fopen(argv[1], "r");

	while (fgets(task,SIZE,in) != NULL) {
		temp = strdup(task);
		name = strsep(&temp,",");
		priority = atoi(strsep(&temp,","));
		burst = atoi(strsep(&temp,","));

		// add the task to the scheduler's list of tasks
		sched_add(sc, name,priority,burst);

		free(temp);
	}

	fclose(in);

	// invoke the scheduler
	sched_run(sc);
	free(name);

	return 0;
}
