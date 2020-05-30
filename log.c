/* 每隔1秒向文件中写入一行记录 */
/* 每行都有序号索引 连续 */
#include <stdio.h>
#include <stdlib.h>	// exit(1)
#include <errno.h>	// error number
#include <unistd.h>	// sleep
#include <time.h>	// time, ctime
#define SEC 1

int main(void){
	time_t ti = 0;
	int i = 0;
	FILE *file = fopen("text.txt","w");
	if (NULL == file) i = 1;
	if(EOF == fclose(file)) {
		perror ("failed to close text.txt");
		exit(1);
	}
	file = fopen("text.txt", "a+");
	if (NULL == file){
		perror("Try to creat text.txt failed");
		printf("errno: %d\n", errno);
		exit(1);
	}
	while(1){
		ti = time(NULL);
		fputs(ctime(&ti), file);	//TODO 写入序号
		fflush(file);
		printf("%s", ctime(&ti));	// ctime字符串自带换行副\n
		sleep(SEC);
	}
	return 0;
}
	
