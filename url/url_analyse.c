/* url.analyse.c */
/* url analyse: http://www.163.com/s?wd=linux&ccl=2&fdf=22
 本函数目的是分析上述字符串，然后传出‘？’之后每个查询字符串，比如key=wd, value=linux就是一个 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char *key;
	char *value;
}meta;

void *url_analyse (const char *u, meta *kv){
	char *begin = NULL, *ch;
	/* 格式检查，必须包含http或者www，必须有问号且问号后不能为空 */
	if (strstr(u,"http")==NULL || strstr(u,"www")==NULL || strchr(u,'?')==NULL){
		printf("%s","format error\n");
		exit(1);	
	}
	begin = strchr(u,'?');
	if (*(ch = ++begin) =='\0') {
		printf("%s","format error\n");
		exit(1);
	}
	/**************************************************************/
	for (; *ch != '\0'; ++ch){
		if (*ch == '='){
			kv->key = (char*)malloc(sizeof(char) * (ch-begin+1));	// 多申请一个单位内存用于'\0'
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

void strt_free(meta *kv){
	free(kv->key);
	free(kv->value);
	}
//TODO meta数组生成，存储以及释放; 头文件体系; 回调函数？

int main(void){
	char *str = "http://www.163.com/s?wd=linux"; //&ccl=2&fdf=22";
	meta kv_group;
	url_analyse(str, &kv_group);
	printf ("key = %s\nvalue = %s\n",kv_group.key, kv_group.value);
	strt_free(&kv_group);
	return 0;
}
