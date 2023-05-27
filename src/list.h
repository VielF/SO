#ifndef _queue_h_include_
#define _queue_h_include_

#include "task.h"

typedef struct ListNode ListNode;
typedef struct List List;

struct ListNode {
	ListNode* next;
	Task* task;
};

struct List {
	ListNode* head;
};

// Create list
List list_new();
// De-alloc list
void list_del(List* l);
// Add element to list
void list_add(List* l, Task* task);
// Search and remove element from list
void list_rm(List* l);
// Print list
void list_display(const List* l);

#endif /* Include guard */
