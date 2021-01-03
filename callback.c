/* 回调函数案例 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _OP {
	float (*p_add)(float, float);
	float (*p_sub)(float, float);
	float (*p_mul)(float, float);
	float (*p_div)(float, float);
}OP;

float ADD(float a, float b){
	return a+b;
}
float SUB(float a, float b){
	return a-b;
}
float MUL(float a, float b){
	return a*b;
}
float DIV(float a, float b){
	return a/b;
}

void init_op(OP *op){
	op->p_add = ADD;
	op->p_sub = SUB;
	op->p_mul = &MUL;
	op->p_div = &DIV;
}
/* add sub multiply div */
float asmd(float a, float b, float (*op_func)(float, float)){
	return (*op_func)(a,b);
}

int main(void){
	OP *op = (OP *)malloc(sizeof(OP));
	init_op(op);

	printf ("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", (op->p_add)(1.3,2.2), (*op->p_sub)(1.3, 2.2), (op->p_mul)(1.3, 2.2),(*op->p_div)(1.3,2.2));

	printf ("ADD=%f, SUB=%f, MUL=%f, DIV=%f\n", asmd(1.3, 2.2, ADD), asmd(1.3,2.2,SUB),asmd(1.3,2.2,MUL),asmd(1.3,2.2,DIV));

	return 0;
}
