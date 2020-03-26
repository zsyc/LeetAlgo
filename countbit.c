#include <stdio.h>

int countbit(unsigned int x){
	unsigned int a=x, mask=0x1, count=0;
	while (a!=0){
		if (a & mask == 1)	++count;
		a>>=1;
	}
	return count;
}

int main(){
	unsigned int x;
	scanf("%d", &x);
	printf("There are %d bits with '1'.\n", countbit(x));

	return 0;
}
