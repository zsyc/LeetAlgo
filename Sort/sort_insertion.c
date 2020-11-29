# include <stdio.h>
# define LEN 30
// 插入排序法，每次排序前，key 前方的“子”数列都是有序的
int b[LEN] = {10,122,2,4,7,321,54,3,2,54,56,45,6,543,8,9,0,2,32,32,4,6,546,546,546,54,6546,546,3213,0};

void sort_insert(int a[], int len){
	int tmp, N=0;
	for (int i = 1; i < len; ++i)
		for (int j = i; j > 0 && a[j] < a[j-1]; --j){	//这里j不能=0,否则a[j-1]将会越界
			tmp = a[j];
			a[j] = a[j-1];
			a[j-1] = tmp;
			++N;
		}
	printf ("sort_insert exchange %d times\n", N);
}

int main(void){
	sort_insert(b,LEN);
	for (int i=0;i<LEN;++i)
		printf ("%d ", b[i]);
	putchar('\n');
	return 0;
}

