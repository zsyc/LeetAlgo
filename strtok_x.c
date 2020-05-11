//strtok_x.c
#include <stdio.h>
char *strtok_x(char *s, const char *delim){
	static char *next = NULL;
	char *ch = NULL;
	if (s!=NULL){
		while (*s == *delim || *s==' ') ++s;
		next = s;
		ch = next;
	}
	else{
		ch = next;
		s = next;
	}
	
	while (*ch != '\0'){
		if (*ch == *delim) {
			*ch = '\0';
			next = ++ch;
			if (*next == *delim) continue;
			return s;
		}
		++ch;
	}
	if (*s != *delim && *s != ' ') printf ("--->%s\n", s);
	return NULL;
}
//当前问题：对空格处理不正确，对末尾冒号处理不正确
