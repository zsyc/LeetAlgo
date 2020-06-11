/* 链表 */
/* loglink.h */

#ifndef LOGLINK_H
#define LOGLINK_H

typedef struct node *link;
struct node{
	char line[40];
	link pre, next;
};

link make_node(const char*);	//返回新的链结指针
void insert(link);
void sortlink(void);
link travel(void(*)(link));	//返回head指针

#endif
