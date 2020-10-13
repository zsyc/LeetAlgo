#include <stdio.h>

#define LEN 10
int a[LEN] = {5,2,4,7,1,3,2,6,10,9};
int b[LEN] = {3,1,11,0,6,5,5,1,0,4};

/* 思路是使用i,j两个索引，分别从左与从右相向移动，
 * 当a[i]>key 并且a[j]<key时（轮流移动），交换位置
 * 最后，返回索引i，作为下一次的mid值(此时此刻，i左边的比a[i]小，i右边的比a[i]大*/
int partition (int start, int end){
	int key = a[start], i = start, j = end;
	int tmp;
	while(i<j){
		if (a[j]>=key){
			--j;
			continue;
		}
		if (a[i]<=key){
			++i;
			continue;
		}
		tmp = a[i];
		a[i]= a[j];
		a[j--]= tmp;
	}
    a[start] = a[i];
	a[i] = key;
	return i;
}

/* 另一种写法
 * 还是双索引，i索引始终指向小于key的数要放的位置，j索引则从左往右扫描，
 * 碰到小于key的数字，则移动到i的位置
 * 随机性对平均算法时间很重要，因而key的值可以首先随机选出，然后与最后一个数值对掉 
 * 上方写法同理 */

int partition2(int lo, int hi){
	int key = b[hi], i = lo-1, j = lo, tmp;
	for (;j<hi; ++j)
		if (b[j] <= key){
			tmp = b[++i];
			b[i] = b[j];
			b[j] = tmp;
		}	
	b[hi] = b[++i];
	b[i] = key;
	return i;
}


void quicksort (int start, int end){
	int mid;
	if (end>start){
		mid = partition(start, end);
		quicksort(start, mid-1); 
		quicksort(mid+1,end);
	}
}
void quicksort2 (int start, int end){
	int mid;
	if (end>start){
		mid = partition2(start, end);
		quicksort2(start, mid-1); 
		quicksort2(mid+1,end);
	}
}
int main(void){
	quicksort(0,LEN-1);
	printf("%d %d %d %d %d %d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
	quicksort2(0,LEN-1);
	for (int i=0; i<LEN;++i)
		printf("%d ",b[i]);
	putchar('\n');
	return 0;
}

