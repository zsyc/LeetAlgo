#include <stdio.h>

unsigned int rotate(unsigned int x, int bits){
	//本例是用来进行循环移位操作，输入值为无符号十六进制。bits为正则右移位，否则左移位
	unsigned int value=x, mvbit;
	if (bits>=0)
		for (int i = 0; i<bits; ++i){
			mvbit = value & 0x1;
			mvbit <<= 31;
			value = (value>>1)+mvbit;
		}
	else
		for (int i = 0; i<(-bits); ++i){
			mvbit = value & 0x80000000;
			mvbit >>= 31;
			value = (value<<1)+mvbit;
		}
	return value;
}

int main(){
	unsigned int x;
	int bits;
	scanf("%x %d", &x,&bits);
	printf("%x\n", rotate(x,bits));

	return 0;
}
