/* 环形链表方法 */
/* linked.c */

#include <stdlib.h>
#include "linked.h"

struct node doublelist = {0, &doublelist, &doublelist};	//界定表头，不保存数据
static link head = &doublelist;

link make_node(unsigned char item){
	link p = (link)malloc(sizeof(*p));
	p->item = item;
	p->pre = p->next = NULL;
	return p;
}

link search (unsigned char key){
	link p;
	for (p = head->next; p != head; p = p->next)
		if (p->item == key)
			return p;
	return NULL;
}

void insert (link p){	//在head后面插入
	p->next = head->next;
	head->next->pre = p;
	p->pre = head;
	head->next = p;
}

void del(link p){
	if (p!=head){
		p->pre->next = p->next;
		p->next->pre = p->pre;
		free(p);
	}
}

void destroy(void){
	link q, p = head->next;
	head->next = head;
	head->pre = head;
	while(p != head){
		q = p;
		p = p->next;
		free(q);
	}
}

link travel(void (*visit)(link)){
	for (link p=head->next; p!=head; p=p->next)
		visit(p);
	return head->next;
}
