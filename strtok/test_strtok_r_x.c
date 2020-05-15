#include <stdio.h>
#include "strtok_r_x.h"

int main(int argc, char *argv[]){
//	char strx[] = ":::acc::  ::kkevn:: ::d::::  d";
	char *ch = NULL, *saveptr = NULL;
	ch = strtok_r_x(argv[1], argv[2], &saveptr);
	printf ("-->%s\n",ch);
	while ((ch = strtok_r_x(NULL,argv[2], &saveptr))!=NULL)
		printf ("-->%s\n", ch); 

	return 0;
}
 
