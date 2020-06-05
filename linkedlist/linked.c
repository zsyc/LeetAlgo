/* 环形链表方法 */
/* linked.c */

#include <stdlib.h>
#include "linked.h"

struct node doublelist = {0, &doublelist, &doublelist};
static link head = &doublelist;

link make_node(unsigned char item){
	link p = (link*)malloc(sizeof(*p));
	p->item = item;
	p->pre = p->next = NULL;
	return p;
}

void free_node(link p){
	free(p);
}

link search (unsigned char key){
	link p;
	for (p = head->next; p != head; p = p->next)
		if (p->item == key)
			return p;
	return NULL;
}

void insert (link p){	//在head后面插入, TODO head要不要移动？
	p->next = head->next;
	head->next>pre = p;
	p->pre = head;
	head->next = p;
}


