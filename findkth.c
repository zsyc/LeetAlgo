#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 在不排序的前提下，寻找一个随机数列中第kth元素，这里使用递归,核心类似于中位数的中位数算法。
 * 这里的partition算法实现的依旧是把随机的pivot放在合适的位置，使得它左边的数比它小，右边的比它大
 * 总体思路是在数列中随机挑一个数，通过partition确定它的位置是否为k，如果不是：
 * 若这个位置比k小，则在其右方区域再次寻找
 * 若比k大，则在其左方区域寻找 */

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

int findkth(int arr[], int N, int left, int right, int k){	//N为数组长度
	int index;
	if (k<1 || k>N) {
		printf("%s", "Index out of range.");
		return -1;
	}
	index = partition(arr, left, right);
	if (index+1==k) return arr[index];
	if (index+1<k) return findkth(arr, N, index+1, right, k);
	else return findkth (arr, N, left, index-1, k);
}

int main(void){
	int arr[11] = {2,36,5,21,8,13,11,20,5,4,1};
	int k;
	printf("%s\n", "In this array[2,36,5,21,8,13,11,20,5,4,1], which kth element do u want to print?");
	scanf("%d", &k);
	printf("%d\n", findkth(arr,11,0,10,k));
}
