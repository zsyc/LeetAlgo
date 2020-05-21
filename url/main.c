/* main.c */
#include "url_parse.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	const char *const str = "http://www.163.com/s?wd=linux&ccl=2&fdf=22&asdf=123&cvn=sad";
	const char *u = str;	//因为接下来要移动指针，所以复制出来使用，保证str指针的不变
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
	strk_free(kv_group, anzahl);
	free(kv_group);	
	kv_group = NULL;
	return 0;
}
