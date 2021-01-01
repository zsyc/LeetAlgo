/* binheap.c */
/* 二叉堆堆有序：就是每个结点都[小于等于]它的父结点，从上到下从大到小
 * 位置k的结点的父结点为k/2，子结点为2k与2k+1，
 * 因此可以按照这个来放入数组, 放弃0号位置 */

/* 由下至上的堆有序化
 * 当某个结点比父结点大，交换这个结点与父结点
 * 若交换后依旧比新的父结点大，那么继续交换。
 * 直到，结点不再大于其父结点 */
#include <stdio.h>
#include "binheap.h"

// 二叉堆 pq[], 最大索引为N，因为C语言数组为静态，所以数组初始设大一些，例如255
//上浮法
void swim(int k, int pq[], int N){
	int tmp;
	while (k>1 && pq[k/2] < pq[k]){ //父结点小于子结点时
		tmp = pq[k/2];
		pq[k/2] = pq[k];
		pq[k] = tmp;
		k/=2;
	}
}

//下沉法, 与子结点中的较大者进行交换，否则的话交换后，会产生新的反序
void sink(int k, int pq[], int N){
	int tmp;
	while (2*k<=N){
		int j = 2*k;
		if (j<N && pq[j]<pq[j+1]) ++j;
		if (pq[k] < pq[j]){
			tmp = pq[k];
			pq[k] = pq[j];
			pq[j] = tmp;
		}
		k = j;
	}
}

// 插入元素：新元素加入数组末尾，增加堆大小并让元素上浮——不超过（lgN+1）次比较
void insert(int key, int pq[], int N){
	pq[++N] = key;
	swim(key, pq, N);
}

// 删除最大元素：把根节点与末位元素交换，然后下沉新的根节点到正确位置——不超过(2lgN)次——返回最大元素
int delMax(int pq[], int N){
	int tmp = pq[1];
	pq[1] = pq[N];
	pq[N--] = tmp;
	sink(1,pq,N);
	return tmp;
}
