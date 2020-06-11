/* 链表 */
/* loglink.c */

#include <stdlib.h>
#include <string.h>
#include "loglink.h"

struct node tailsentinel;
struct node headsentinel = {"", NULL, &tailsentinel};
struct node tailsentinel = {"", &headsentinel, NULL};
static link head = &headsentinel;
static link tail = &tailsentinel;

link make_node(const char *str){
	link p = (link)malloc(sizeof(*p));
	strcpy(p->line,str);
	p->pre = p->next = NULL; 
	return p;
}

void insert (link p){	//在tail前面插入
	p->next = tail;
	p->pre = tail->pre;
	tail->pre->next = p;
	tail->pre = p;
}

link travel(void (*visit)(link)){
	for (link p=head->next; p!=tail; p=p->next)
		visit(p);
	return head->next;
}
