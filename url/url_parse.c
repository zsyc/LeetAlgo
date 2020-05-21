/* url.parse.c */
/* url parse: http://www.163.com/s?wd=linux&ccl=2&fdf=22
 本函数目的是分析上述字符串，然后传出‘？’之后每个查询字符串，比如key=wd, value=linux就是一个 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char *key;
	char *value;
}meta;

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

void strt_free(meta *kv, int n){
	while (n>0){
		free(kv->key);
		free(kv->value);
		kv->key = NULL;
		kv->value = NULL;
		++kv;
		--n;
	}
}
//TODO meta数组生成，存储以及释放; 头文件体系
/* main.c */
int main(void){
	const char *str = "http://www.163.com/s?wd=linux&ccl=2&fdf=22&asdf=123&cvn=sad";
	const char *u = str;
	int anzahl;
	meta *kv_group;

	/* kv_group malloc */
	while ( *u != '\0'){
		if (*u == '=') ++anzahl;
		++u;
	}
	kv_group = (meta*)malloc(sizeof(meta) * anzahl);
	if (NULL == kv_group) {
		printf ("out of memory");
		exit(1);
	}
	
	/***********************/
	url_parse(str, kv_group);
	for (int i=0;i < anzahl; ++i)
		printf ("metadate %d:\nkey = %s\nvalue = %s\n\n",i, kv_group[i].key, kv_group[i].value);
	
	/* free memory */
	strt_free(kv_group, anzahl);
	free(kv_group);	
	kv_group = NULL;
	return 0;
}
