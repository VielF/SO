#ifndef _queue_h_include_
#define _queue_h_include_

#include "task.h"

typedef struct ListNode ListNode;
typedef struct List List;

struct QueueNode {
	ListNode* next;
	Task* task;
};

struct List {
	ListNode* head;
};

void q_enqueue(List* l, Task* task);
void q_dequeue(List* l);
void q_display(const List* l);

#endif /* Include guard */
