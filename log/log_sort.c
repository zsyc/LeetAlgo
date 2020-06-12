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

link log2link(void){
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

void get_time(const char *line, int *month, int *day, int *hour, int *min, int *sec){
	char monat[4];	// 月份缩写为三个大写字母，多出来的放'\0'
	sscanf(line, "%*d %*s %s%d%d:%d:%d%*d", monat, day, hour, min, sec);
	switch(monat[0]){
		case 'J':	// J开头的有若干月份选项
			if ('a' == monat[1]) *month = 1;
			else if ('l' == monat[2]) *month = 7;
			else *month = 6;
			break;
		case 'F':
			*month = 2;
			break;
		case 'M':
			if ('r' == monat[2]) *month = 3;
			else *month = 5;
			break;
		case 'A':
			if ('p' == monat[1]) *month = 4;
			else *month = 8;
			break;
		case 'S':
			*month = 9;
			break;
		case 'O':
			*month = 10;
			break;
		case 'N':
			*month = 11;
			break;
		default:
			printf("no month data! Program treat month as the first");
			*month = 0;
	}
}	

int main(void){
	int month, day, hour, min, sec;
	link HEAD = log2link()->pre;
	get_time("11	Thu Jun 11 19:37:28 2020",&month, &day, &hour, &min, &sec);
	printf("%d %d %d %d %d\n", month, day, hour, min, sec);
	return 0;
}

