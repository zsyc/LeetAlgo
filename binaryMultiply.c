#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y){
	//二进制乘法，写成竖列式，可以看做若干数字相加，如：(0b11011)*(0b10010)= 0b11011<<1+0b11011<<4,1与4分别是乘数中为1的比特位
	unsigned int bit=0, factor=y, mask=0x1, product=0;
	if (y==0) return 0;
	while(factor!=0){
		if (factor&mask==1) product += x<<bit;
		factor>>=1;
		++bit;
	}
	return product;
}

int main(){
	unsigned int x,y;
	scanf("%d %d", &x,&y);
	printf("%d multiply %d is %d\n", x,y,multiply(x,y));

	return 0;
}
