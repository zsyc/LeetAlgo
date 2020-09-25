/* sort_merge.c */
/* 归并排序 */
#include <stdio.h>

void merge(int a[], int lo, int mid, int hi){
	int i = lo, j = mid+1;	//对半分后，左边序列从lo到mid,右边从mid+1到hi
	int aux[10];
	for (int k = lo; k <= hi; ++k)
		aux[k] = a[k];
	for (int k = lo; k <= hi; ++k){
		if (i > mid)				a[k] = aux[j++];//左边索引超过中线，则把右侧剩余元素全部复制
		else if (j > hi)			a[k] = aux[i++];//同上
		else if (aux[j] < aux[i]) 	a[k] = aux[j++];
		else						a[k] = aux[i++];
	}
}

/* 自顶向下，分治，递归 */
void sort_down(int a[], int lo, int hi){
	if (lo<hi){
		int mid = lo + (hi-lo)/2;
		sort_down(a, lo, mid);
		sort_down(a, mid+1, hi);
		merge(a,lo,mid,hi);
	}
}

/* 自底向上，循环 
 * 先把长度为2的小数组归并排序，0-1,1-2,3-4,5-6,...
 * 然后是长度为4的小数组，0-3,4-7,8-11,...*/
void sort_up(int a[],int N){	//N：数组长度
	for (int size = 2; size/2 < N; size*=2)
		for (int lo=0; lo < N; lo+=size)
			merge(a,lo,lo+size/2-1,(lo+size-1<N-1 ? lo+size-1 : N-1));
}

int main(void){
	int a[10] = {3,4,6,78,11,2,6,54,0,32};
	int b[10] = {3,4,6,78,11,2,6,54,0,32};
	sort_down(a,0,9);
	sort_up(b,10);
	for (int i=0;i<10;++i)
		printf("%d ",a[i]);
	putchar('\n');
	for (int i=0;i<10;++i)
		printf("%d ",b[i]);
	putchar('\n');
	return 0;
}
