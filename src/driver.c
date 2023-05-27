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
	char* filedata = NULL;
	char task[SIZE];
	Scheduler* sc = sched_new();

	char *name;
	int priority;
	int burst;

	filedata = loadfile(argv[1]);
	printf("=== FILE ===\n%s\n=== EOF ==\n", filedata);

	// invoke the scheduler
	sched_run(sc);

	// Cleanup
	sched_del(sc);
	free(filedata);
	return 0;
}
