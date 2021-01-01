/* binheap.h */
#ifndef BINHEAP_H
#define BINHEAP_H
void swim(int k,int pq[],int N);
void sink(int k,int pq[],int N);
void insert(int key,int pq[],int N);
int delMax(int pq[],int N);
#endif
