/* log.c */
/* 每隔1秒向文件中写入一行记录 */
/* 每行都有序号连续索引，并且多次执行都可以接续之前索引 */
#include <stdio.h>
#include <stdlib.h>	// exit(1)
#include <string.h>	// strlen
#include <errno.h>	// error number
#include <unistd.h>	// sleep
#include <time.h>	// time, ctime
#define SEC 1

/* 为了接续索引，记录前需要判断文件是否存在，如果不存在那么直接从1开始计数；
 * 如果存在，则从文件末尾向文件开头移动指针，找到最后一个索引数i，然后从i+1开始计数 */
int main(void){
	time_t ti = 0;
	int i = 0;
	char ch;
	FILE *file = fopen("text.txt","r");
	if (NULL == file) i = 1;	// 判断文件是否已经存在
	else if(EOF == fclose(file)) {
		perror ("failed to close text.txt");
		exit(1);
	}
	file = fopen("text.txt", "a+");
	if (NULL == file){
		perror("Try to creat text.txt failed");
		printf("errno: %d\n", errno);
		exit(1);
	}
	if (1 == i)		// 文件不存在 
		while(1){
			ti = time(NULL);
			fprintf(file, "%d\t%s", i++, ctime(&ti));
			fflush(file);		//强制从缓冲区写入文件，因为这是无限循环
			printf("%s", ctime(&ti));	// ctime字符串自带换行副\n
			sleep(SEC);
		}
	else{		//文件已存在
		fseek(file, 0, SEEK_END);
		while ((ch = fgetc(file)) != '\n')	//文件末尾没有换行符，逆向找到的第一个换行符后面的数字就是最后一次记录
			fseek(file, -2, SEEK_CUR);	//因为每次fgetc后文件指针会自动移动，所以需要移动2个单位
		fscanf(file, "%d", &i);
		++i;
		fseek(file,0,SEEK_END);		//定位到文件末尾准备写入
		ti = time(NULL);
		while(1){
			ti = time(NULL);
			fprintf(file, "%d\t%s", i++, ctime(&ti));
			fflush(file);		//强制从缓冲区写入文件，因为这是无限循环
			printf("%s", ctime(&ti));	// ctime字符串自带换行副\n
			sleep(SEC);
		}
	}

	return 0;
}
