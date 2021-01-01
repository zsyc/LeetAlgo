/* sort_heap.c 堆排序 */
/* 思路：对既有无序数组，使用sink从右往左进行排序构造子堆，比使用swim从左往右扫描数组更好，因为可以避开大小为1的子堆
 * 这样少于2N次比较，少于N次交换
 * 下面首先是把无序数组构造为堆有序，但堆有序并不代表数组有序
 * 然后，通过删除最大元素，也就是pq[1]，把最大元素与数组尾部元素交换，然后下沉新的根结点到正确位置（排除尾部元素）
 * 反复删除最大元素，这样最后，当堆的N为1时，数组已经排序 */

#include <stdio.h>
#include "binheap.h"

void sort_heap(int pq[], int N){
	for (int k=N/2; k>=1; --k)	// 从N/2开始，避开大小为1的子堆
		sink(k, pq, N);			// 构造完成
	while (N>1){
		int tmp = pq[1];
		pq[1] = pq[N];
		pq[N--] = tmp;
		sink(1, pq, N);
	}
}

int main(void){
	int pq[11] = {0,2,3,5,7,0,1,1,23,12,4};	//0索引不考虑
	sort_heap(pq, 10);
	for (int i = 1; i<=10;++i)
		printf ("%d ",pq[i]);
	putchar ('\n');

	return 0;
}
