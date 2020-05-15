//strtok_x.c
#include <stdio.h>
static int in(char, const char*);
char *strtok_x(char *s, const char *delim){
	static char *next = NULL;	//用于保存下一次分隔的位置指针
	char *ch = NULL;
	// 去除字符串先导所有无关字符
	if (s!=NULL){
		while (*s==' ' || in(*s, delim)) ++s;
		next = s;
	}
	// 当s为NULL, 意味着这不是第一次分隔
	else
		s = next;
	
	// 每次碰到分隔符，就把它替换成'\0'，然后跳过所有非相关字符
	while (*(ch=next) != '\0'){
		if (in(*ch, delim)){
			*ch = '\0';
			++ch;
			while(*ch == ' ' || in(*ch, delim))
				++ch;
			next = ch;		//保存下次开始的指针位置
			return s;
		}
		++next;
	}
	if (*s != '\0') return s;	//当进行到最后一段时，打印
	return NULL;
}

/* 本函数用于分辨多个分隔符，若上面的ch属于其中之一，则返回1 */
static int in(char ch, const char *delim){
	while (*delim != '\0'){
		if (ch == *delim) return 1;
		++delim;
	}
	return 0;
}
