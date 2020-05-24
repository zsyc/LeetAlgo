/* cp_char.c */
/* 实现文件复制 ./mycp dir1/fileA dir2/fileB */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

enum unit{CHAR,STRING};
struct cp_md{
	enum unit t;
}
#define copywith(cp_md,res,des) copy_method[cp_md](res,des)

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
	while ((s = fgets(s, 43, file1)) != NULL)
		if (fputs(s, file2) == EOF){
			printf("Error writing");
			exit(1);
		}
	if (fclose(file2) == EOF) printf ("Close new file failed");
	if (fclose(file1) == EOF) printf ("Close resource file failed");
}	

//TODO 方法选择 回调？
int main(int argc, char *argv[]){
	if (argv[1] != "CHAR" && argv[1] != "STRING"){
		printf("Copy with the unit of [CHAR] or [STRING]? Please input the method as first parameter.\n");
		exit(1);
	}
	copywith(argv[1], argv[2], argv[3]);
//	cp_char(argv[1], argv[2]);
//	cp_string(argv[1], argv[2]);
	
	return 0;
}
