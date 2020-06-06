/* 一圈人，每次数到三的那个人出圈。
 * 本题意在找出最后一个幸存者，一共N人，每次数到M */
/* Josephus.c */

#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

void show_item(link p){
	printf("%d ",p->item);
}

int main(int argc, char *argv[]){
	int M=atoi(argv[1]), N=atoi(argv[2]);
	link p=NULL, q=NULL, HEAD=NULL;
	for (int i=M;i>0;--i)
		insert(make_node(i));
	p = travel(show_item);
	HEAD = p->pre;
	putchar('\n');
	while(1){
		for (int i=N-1; i>0; --i){
			p = p->next;
			if (p == HEAD) p = p->next;	//head不应该参与计数
		}
		if (p->next==HEAD && p->pre==HEAD) break;
		q = p;
		p = p->next==HEAD ? p->next->next:p->next;
		del(q);
		travel(show_item);
		putchar('\n');
	}
		
	travel(show_item);
	putchar('\n');
	return 0;
}
