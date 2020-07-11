/* 双向链表 */
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
	strcpy(p->line,str);	//不可赋值指针，会指向同一内容！
	p->pre = p->next = NULL; 
	return p;
}

void insert (link p){	//在tail前面插入
	p->next = tail;
	p->pre = tail->pre;
	tail->pre->next = p;
	tail->pre = p;
}

void swap (link *p, link *q){
	link tmp = (link)malloc(sizeof(*tmp));
	if ((*q) != (*p)->next){	// 非相邻元素交换
		(*p)->pre->next = (*q);
		(*p)->next->pre = (*q);
		(*q)->pre->next = (*p);
		(*q)->next->pre = (*p);
		tmp->pre = (*q)->pre;
		tmp->next = (*q)->next;
		(*q)->pre = (*p)->pre;
		(*q)->next = (*p)->next;
		(*p)->pre = tmp->pre;
		(*p)->next = tmp->next;
		free(tmp);
	}
	else {		//相邻元素交换
		(*p)->pre->next = (*q);
		(*q)->pre = (*p)->pre;
		(*p)->next = (*q)->next;
		(*p)->pre = (*q);
		(*q)->next = (*p);
		(*p)->next->pre = (*p);
	}

	tmp = (*p);	//调整p q指向序列不变
	(*p) = (*q);
	(*q) = tmp;
	tmp = NULL;
}

link getHead(void){
	return head;
}
link getTail(void){
	return tail;
}

void travel(void (*visit)(link)){
	for (link p=head->next; p!=tail; p=p->next)
		visit(p);
}
