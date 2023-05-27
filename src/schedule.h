// Generic scheduler interface

#ifndef _schedule_h_include_
#define _schedule_h_include_

#include "list.h"
#include "task.h"
#include <stdio.h>
#include "CPU.h"

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

typedef struct Scheduler Scheduler;

// allocate scheduler
extern Scheduler* sched_new();

extern void sched_remove(Scheduler* sc, Task* task);
// invoke the scheduler
extern void sched_run(Scheduler* sc);

// add a task to the list
extern void sched_add(Scheduler* sc, char *name, int priority, int burst);

// de-allocate scheduler
extern void sched_del(Scheduler* sc);

#endif /* Include guard */
