/* 环形链表 */
/* linked.h */

#ifndef LINKED_H
#define LINKED_H

typedef struct node *link;
struct node{
	unsigned char item;
	link pre, next;
};

link make_node(unsigned char);
link search(unsigned char);
void insert(link);
void del(link);
void destroy(void);
link travel(void(*)(link));

#endif
