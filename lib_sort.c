/* lib_sort.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib_sort.h"

/* partition实现的是，在数列中任取一个数值，然后把所有小于这个数值的放在它左边，
 * 大于这个数值的放在右边，最后返回这个数值当前索引，也就是”从小到大“的位置 */

int partition(int arr[], int left, int right){
	/* 这里使用随机数是为了保证算法复杂度的可靠性 */
	int tmp, pivot, i=left-1,pivot_tmp;
	srand(time(NULL));
	if (right>=left){
		pivot_tmp= rand()%(right-left) + left; //rand()生成0到RAND_MAX之间的数值，这里用余数来限定上下限为[left,right)
		tmp = arr[pivot_tmp];
		arr[pivot_tmp] = arr[right];
		arr[right] = tmp;
	}
	/**********************************************/
	pivot = arr[right];
	for (int j=left;j<right;++j)
		if (arr[j] <pivot){
			i += 1;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	tmp = arr[i+1];
	arr[i+1] = arr[right];	//这里arr[right]的位置就是pivot，把pivot放在i+1的位置，之前的数字都比pivot小
	arr[right] = tmp;

	return i+1;
}

