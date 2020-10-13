/* sort_shell.c */
/* 希尔排序首先是分组排序，例如第0个元素与第4个元素，
 * 第1个与第5个元素……排序，如果发生了交换，那么交换后前一个元素需要与同一组之前的元素再排序，否则下一组*/

#include <stdio.h>
#include <stdlib.h> //rand
#include <time.h>
#define N 30
/* a为待排序序列，len为序列元素数量 */
void sort_shell(int a[], int len){
	int inc=1, tmp;
	while (inc<len/3) inc = 3*inc+1;
	while (inc>=1){
		for (int i=inc; i<len; ++i)
			for (int j=i; j>=inc && a[j]<a[j-inc]; j-=inc){	//之所以j不直接初始化为i-inc，是为了防止越界
				tmp = a[j];
				a[j] = a[j-inc];
				a[j-inc] = tmp;
			}
		inc/=3;
	}
}

int main(void){
	srand(time(NULL));	//以当前时间作为随机数种子，在此刻随机数序列确定，time函数返回time_t类型，一般为int
	int a[N];
	for (int i=0; i<N; ++i)
		a[i] = rand()/1000;
	int len = sizeof(a)/sizeof(int);
	printf("%d\n", len);
	sort_shell(a, len);
	for (int i=0;i<len;++i)
		printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}	
