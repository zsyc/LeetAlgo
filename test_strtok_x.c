#include <stdio.h>
#include "strtok_x.h"

int main(int argc, char* argv[]){
//	char strx[] = ":::acc:::kkevn::::d::::";
	char *ch = NULL;
	ch = strtok_x(argv[1], argv[2]);
	printf ("-->%s\n",ch);
	while ((ch = strtok_x(NULL,argv[2]))!=NULL)
		printf ("-->%s\n", ch); 
		

	return 0;
}
 
