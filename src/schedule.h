// Generic scheduler interface

#ifndef _schedule_h_include_
#define _schedule_h_include_

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

typedef struct Scheduler Scheduler;

// allocate scheduler
extern Scheduler* sched_new();

// invoke the scheduler
extern void sched_run(Scheduler* sc);

// add a task to the list 
extern void sched_add(Scheduler* sc, char *name, int priority, int burst);

#endif /* Include guard */
