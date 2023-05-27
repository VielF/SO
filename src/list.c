#include "list.h"
#include <stddef.h>
#include <stdlib.h>

List list_new(){
	return (List) {
		.head = NULL,
		.len = 0,
	};
}

static void list_node_del(ListNode* node){
	if(node == NULL){ return; }
	task_del(node->task);
	free(node->task);
	free(node);
}


void list_del(List* l){
	if(l == NULL){ return; }
	ListNode* cur = l->head;
	while(cur != NULL){
		ListNode* next = cur->next;
		list_node_del(cur);
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
		// TODO: Change this to pointer instead of ID comparison
		if(cur->task->tid == task->tid){
			if(prev == NULL){
				l->head = cur->next;
			} else {
				prev->next = cur->next;
			}
			list_node_del(cur);
			l->len -= 1;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}


void list_display(const List* q){}
