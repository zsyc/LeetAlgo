#include "stdio.h"
int factor(int a, int b){	//注意，a大于等于b
	if (a%b==0) return b;
	return factor(b,a%b);
}

int main(void){
	int a,b;
	printf ("输入需要求最大公约数的两整数：\n");
	scanf ("%d %d", &a,&b);
	if (a>=b) printf("%d\n", factor(a,b));
	else printf("%d\n", factor(b,a));
	return 0;
}
