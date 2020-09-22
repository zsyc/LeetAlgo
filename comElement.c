/* 求三个有序数组（可以不等长）的共同元素
 * 用三个索引分别对应三个数组（为了减小时间复杂度，没有合并数组，因为那样会不得不使用嵌套循环）
 * 通过反复两两对比，最后一个else那里是a1>=a2>=a3,因此k自加
 * 这里的时间复杂度应该是O(3N)*/
#include <stdio.h>
static const int N=5;
void comElement(int a1[N], int a2[N], int a3[N]){
	for (int i=0,j=0,k=0; i<N && j<N && k<N;)
		if (a1[i] == a2[j] && a2[j]==a3[k]){
			printf("%d ",a1[i]);
			++i,++j,++k;
		}
		else if (a1[i] < a2[j])
			++i;
		else if (a2[j] < a3[k])
			++j;
		else
			++k;
}

int main(void){
	int a1[5] = {0,1,2,5,6},a2[5]={4,5,7,10,11}, a3[5]={5,12,13,15,22};
	comElement(a1,a2,a3);
	return 0;
}
