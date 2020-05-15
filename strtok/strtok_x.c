//strtok_x.c
#include <stdio.h>
static int in(char, const char*);
char *strtok_x(char *s, const char *delim){
	static char *next = NULL;
	char *ch = NULL;
	if (s!=NULL){
		while (*s==' ' || in(*s, delim)) ++s;
		next = s;
	}
	else
		s = next;
	
	while (*(ch=next) != '\0'){
		if (in(*ch, delim)){
			*ch = '\0';
			++ch;
			while(*ch == ' ' || in(*ch, delim))
				++ch;
			next = ch;
			return s;
		}
		++next;
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
