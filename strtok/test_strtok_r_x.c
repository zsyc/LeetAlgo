#include <stdio.h>
#include "strtok_r_x.h"

int main(int argc, char *argv[]){
//	char strx[] = "peter man 26,alice woman 12,petra man 29"; 使用二级分隔符 "," " "
	char *ch1 = NULL, *ch2 = NULL;
	char *saveptr1 = NULL, *saveptr2 = NULL; 
	char *buf = NULL;
	buf = argv[1];
	while ((ch1 = strtok_r_x(buf, argv[2], &saveptr1)) != NULL){
		printf ("-->%s\n", ch1); 
		buf = NULL;
		while ((ch2 = strtok_r_x(ch1, argv[3], &saveptr2)) != NULL){
			printf ("---->%s\n", ch2);
			ch1 = NULL;
		}
	}

	return 0;
}
 
