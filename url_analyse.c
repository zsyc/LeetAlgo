/* url analyse: http://www.163.com/s?wd=linux&ccl=2&fdf=22 */
// 本函数目的是分析上述字符串，然后传出‘？’之后每个查询字符串，比如key=wd, value=linux就是一个
#include <stdio.h>
#include <string.h>
/* 用结构提保存每个查询字符串 */
typedef struct{
	char *key;
	char *value;
}meta;

void url_analyse (char *u, meta *keyvalue){
}

