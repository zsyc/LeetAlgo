/* cp_char.c */
/* 实现文件复制 ./mycp dir1/fileA dir2/fileB */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

enum {CHAR,STRING};

void cp_char(const char*, const char*);
void cp_string(const char*, const char*);

/* 函数指针的数组，分别对应两种复制方法 */
void (*copy_method[2])(const char*, const char*) = {cp_char, cp_string};

/* 以单字符方式复制,可用于复制各种格式 */
void cp_char(const char *res, const char *des){
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

/* 以字符串方式复制文件，仅用于复制文本文件，二进制文件会出错 */
void cp_string(const char *res, const char *des){
	const int COUNT = 43;
	char *s = (char*)malloc(sizeof(char) * 44);
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
	while ((s = fgets(s, COUNT, file1)) != NULL)
		if (fputs(s, file2) == EOF){
			printf("Error writing");
			exit(1);
		}
	if (fclose(file2) == EOF) printf ("Close new file failed");
	if (fclose(file1) == EOF) printf ("Close resource file failed");
}	

int main(int argc, char *argv[]){
	int md = -1;
	printf ("Copy with unit of char(0) or string(1)?\n");
	scanf("%d", &md);
	switch (md){
		case CHAR: copy_method[CHAR](argv[1], argv[2]);
				   break;
		case STRING: copy_method[STRING](argv[1], argv[2]);
					 break;
	}

	return 0;
}
