#include <stdio.h>
/* 荷兰国旗，或者说快速排序的变化
 * 三索引i j k，k为数值索引，i j分别从左往右与从右往左移动，代表的是
 * i左边的数值都小于key，j右边的都大于key，i j之间的等于key 
 * 这种算法在数列有重复数值的时候更为高效
 * 同样，建议key使用随机找出来，然后可以一开始与本例中的arr[hi]对调一下，剩下相同*/
void sort3way(int arr[], int lo, int hi){
	if (hi<=lo) return;		//递归中止条件
	int key = arr[hi], tmp;
	int i=lo, j=hi;
	for (int k=lo; k<=j;){ //注意这里停止条件为“小于等于”
		if (arr[k]<key){
			tmp = arr[k];
			arr[k++] = arr[i];
			arr[i++] = tmp;
		}
		else if (arr[k]>key){
			tmp = arr[k];
			arr[k] = arr[j];	//注意这里不能向前移动k，因为这个k可能比key小，因而需要再比一次！
			arr[j--] = tmp;
		}
		else ++k;	//当索引k位置的数值等于key的时候，它应该位于i 与j之间，因此位置不变，直接向前移动
	}
	sort3way(arr, lo, i-1);
	sort3way(arr, j+1, hi);
}

int main(void){
	int a[6] = {3,1,5,0,2,4};
	sort3way(a,0,5);
	for (int i=0;i<6;++i)
		printf("%d ",a[i]);
	putchar('\n');

	return 0;
}
