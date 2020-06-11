/* log_sort.c */
/* 之前log.c生成的文件，原本是按照日期-时间排序，改为按照
 * 时间-日期排序 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "loglink.h"

void show_item(link p){
	printf("%s", p->line);
}

link readlog(void){
	FILE *fp = fopen("text.txt","r");
	char ch[40];
	if (NULL == fp){
		printf("unable to open text.txt");
		exit(1);
	}
	while(NULL != fgets(ch, 40, fp))
		insert(make_node(ch));
	fclose(fp);

	return travel(show_item);
}

int main(void){
	readlog();
	return 0;
}

