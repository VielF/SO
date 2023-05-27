#include "list.h"
#include <stddef.h>
#include <stdlib.h>

List list_new(){
	return (List) {
		.head = NULL,
		.len = 0,
	};
}

void list_del(List* l){
	if(l == NULL){ return; }
	ListNode* cur = l->head;
	while(cur != NULL){
		ListNode* next = cur->next;
		task_del(cur->task);
		free(cur->task);
		free(cur);
		cur = next;
	}
	free(cur);
}

void list_add(List* l, Task* task){
	ListNode* new_node = malloc(sizeof(*new_node));
	new_node->task = task;

	new_node->next = l->head;
	l->head = new_node;
	l->len += 1;
}

void list_rm(List* l, Task* task){
	if(l == NULL){ return; }
	ListNode* cur = l->head;
	ListNode* prev = NULL;
	while(cur != NULL){
		if(cur->task->tid == task->tid){
			if(prev == NULL){
				l->head = cur->next;
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
	l->len -= 1;
}


void list_display(const List* q){}
