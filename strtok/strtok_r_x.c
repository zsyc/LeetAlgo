//strtok_r_x.c 与标准版strtok不同的是，_r版本可以支持二级分隔
#include <stdio.h>
static int in(char, const char*);
char *strtok_r_x(char *s, const char *delim, char **saveptr){
//	static char *next = NULL;
	char *ch = NULL;
	if (s!=NULL){
		while (*s==' ' || in(*s, delim)) ++s;
		*saveptr = s;
	}
	else
		s = *saveptr;
	
	while (*(ch=*saveptr) != '\0'){
		if (in(*ch, delim)){
			*ch = '\0';
			++ch;
			while(*ch == ' ' || in(*ch, delim))
				++ch;
			*saveptr = ch;
			return s;
		}
		++(*saveptr);
	}
	if (*s != '\0') return s;
	return NULL;
}

static int in(char ch, const char *delim){
	while (*delim != '\0'){
		if (ch == *delim) return 1;
		++delim;
	}
	return 0;
}
