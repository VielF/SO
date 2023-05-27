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
	if(l->head == NULL) { return; }

	ListNode* cur = l->head;
	ListNode* nextNode = NULL;
	while(cur->next != NULL){
		nextNode = cur->next;
		free(cur);
		cur = nextNode;
	}
	free(cur);
	l->head = NULL;
}

void list_add(List* q, Task* task){
}

void list_rm(List* q){}

void list_display(const List* q){}
