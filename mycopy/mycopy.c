/* mycopy.c */
/* 实现文件复制 ./mycp dir1/fileA dir2/fileB */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void mycopy(const char *res, const char *des){
	int ch;
	FILE *file1 = fopen(res, "r");
	if (NULL == file1){
		perror("Open the file to be copied");
		printf("errno: %d\n", errno);
		exit(1);
	}
	FILE *file2 = fopen(des, "w");
	if (NULL == file2){
		perror("No right to copy file with the path");
		printf("errno: %d\n", errno);
		exit(1);
	}
	while ((ch = fgetc(file1)) !=EOF)
		if(fputc(ch, file2) == EOF){
			printf("Error writing");
			exit(1);
		}
	if (fclose(file2) == EOF) printf ("Close new file failed");
	if (fclose(file1) == EOF) printf ("Close resource file failed");
}

int main(int argc, char *argv[]){
	mycopy(argv[1], argv[2]);

	return 0;
}
