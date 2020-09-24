/* sort_merge.c */
/* 归并排序 */
#include <stdio.h>

void merge_origin(int a[], int lo, int mid, int hi){
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

void sort(int a[], int lo, int hi){
	if (lo<hi){
		int mid = lo + (hi-lo)/2;
		sort(a, lo, mid);
		sort(a, mid+1, hi);
		merge_origin(a,lo,mid,hi);
	}
}
int main(void){
	int a[10] = {3,4,6,78,11,2,6,54,0,32};
	sort(a,0,9);
	for (int i=0;i<10;++i)
		printf("%d ",a[i]);
	putchar('\n');
	return 0;
}
