//strtok_x.c
#include <stdio.h>
char *strtok_x(char *s, const char *delim){
	static char *next = NULL;
	char *ch = NULL;
	if (s!=NULL){
		while (*s == *delim || *s==' ') ++s;
		next = s;
	}
	else
		s = next;
	
	while (*(ch=next) != '\0'){
		if (*ch == *delim){
			*ch = '\0';
			++ch;
			while(*ch == *delim || *ch == ' ')
				++ch;
			next = ch;
			return s;
		}
		++next;
	}
	return NULL;
}
//TODO 多个分隔符
