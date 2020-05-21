/* url.parse.c */
/* url parse: http://www.163.com/s?wd=linux&ccl=2&fdf=22
 本函数目的是分析上述字符串，然后传出‘？’之后每个查询字符串，比如key=wd, value=linux就是一个 */
#include "url_parse.h"	//如果不包含，会出现结构体未定义错误
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void url_parse(const char *u, meta *kv){
	char *begin = NULL, *ch;
	/* 格式检查 */
	if (strstr(u,"http")==NULL || strstr(u,"www")==NULL || strchr(u,'?')==NULL){
		printf("%s","format error\n");
		exit(1);	
	}
	begin = strchr(u,'?');
	if (*(ch = ++begin) =='\0') {
		printf("%s","no date to be parsed\n");
		exit(1);
	}

	/* 开始解析 */
	for (; *ch != '\0'; ++ch){
		if (*ch == '='){
			kv->key = (char*)malloc(sizeof(char) * (ch-begin+1));	// 多一个单位内存用于'\0'
			if (kv->key == NULL){
				printf ("out of memory\n");
				exit(1);
			}
			strncpy (kv->key,begin,ch-begin);
			begin = ch+1;			
		}
		else if (*ch == '&'){
			kv->value = (char*)malloc(sizeof(char) * (ch-begin+1));
			if (kv->value == NULL){
				printf ("out of memory\n");
				exit(1);
			}
			strncpy (kv->value, begin, ch-begin);
			begin = ch+1;
			++kv;
		}
	}
	kv->value = (char*)malloc(sizeof(char) * (ch-begin+1));	//最后没有&分隔符，所以单独加上
	if (kv->value == NULL){
		printf ("out of memory\n");
		exit(1);
	}
	strncpy (kv->value, begin, ch-begin);
}

void strk_free(meta *kv, int n){
	while (n>0){
		free(kv->key);
		free(kv->value);
		kv->key = NULL;
		kv->value = NULL;
		++kv;
		--n;
	}
}
