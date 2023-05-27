#include "list.h"
#include <stddef.h>
#include <stdlib.h>

List list_new(){
	return (List) {
		.head = NULL,
	};
}

void list_del(List* l){
	if(l == NULL){ return; }
	ListNode* cur = l->head;
	while(cur != NULL){
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(l);
}

void list_add(List* l, Task* task){
	ListNode* new_node = malloc(sizeof(*new_node));
	new_node->task = task;

	new_node->next = l->head;
	l->head = new_node;
}

void list_rm(List* q, Task* task){
	if(q == NULL){ return; }
	ListNode* cur = q->head;
	ListNode* prev = NULL;
	while(cur != NULL){
		if(cur->task->tid == task->tid){
			if(prev == NULL){
				q->head = cur->next;
			}else{
				prev->next = cur->next;
			}
			task_del(task);
			free(cur);
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}


void list_display(const List* q){}
