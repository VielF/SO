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

void list_add(List* q, Task task){
	ListNode* new_node = malloc(sizeof(*new_node));
	new_node->task = task;
	new_node->next = NULL;

	if(q->head == NULL){
		q->head = new_node;
		return;
	}

	ListNode* cur = q->head;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = new_node;
}

void list_rm(List* q, Task task){
	if(q == NULL){ return; }
	ListNode* cur = q->head;
	ListNode* prev = NULL;
	while(cur != NULL){
		if(cur->task.tid == task.tid){
			if(prev == NULL){
				q->head = cur->next;
			}else{
				prev->next = cur->next;
			}
			free(cur);
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}


void list_display(const List* q){}
