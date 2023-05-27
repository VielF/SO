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
#include "loadfile.h"
#include "schedule.h"

#define SIZE	100

int main(int argc, char *argv[]){
	if(argc < 2){ return 1; }
	char* temp;
	char** filedata = NULL;
	char task[SIZE];
	Scheduler* sc = sched_new();

	char *name;
	int priority;
	int burst;

	filedata = file_lines(argv[1]);

	sched_add(sc, "Task 1", 1, 10);
	sched_add(sc, "Task 2", 1, 10);
	sched_add(sc, "Task 3", 1, 10);
	sched_add(sc, "Task 4", 1, 10);
	sched_add(sc, "Task 5", 1, 10);

	// invoke the scheduler
	sched_run(sc);

	// Cleanup
	free(filedata);
	sched_del(sc);
	return 0;
}
