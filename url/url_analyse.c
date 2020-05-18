/* url analyse: http://www.163.com/s?wd=linux&ccl=2&fdf=22 */
// 本函数目的是分析上述字符串，然后传出‘？’之后每个查询字符串，比如key=wd, value=linux就是一个
#include <stdio.h>
#include <string.h>
/* 用结构体保存每个查询字符串 */
typedef struct{
	char *key;
	char *value;
}meta;

char *url_analyse (const char *u, meta *kv){
	char *ch;
	if (strstr(u,"http")==NULL || strstr(u,"www")==NULL || strchr(u,'?')==NULL){
		printf("%s","format error");
		return NULL;
	}
	ch = strchr(u,'?');
	++ch;
	//TODO 考虑用字符串复制命令到结构体中，而不是直接更改字符串本身
	
	return NULL;
}

int main(void){
	char *str = "asdbc";
	url_analyse(str);
	return 0;
}
