/* url_parse.h */
#ifndef URL_PARSE_H
#define URL_PARSE_H

typedef struct{
	char *key;
	char *value;
}meta;

extern void url_parse(const char*, meta*);
extern void strk_free(meta*, int);

#endif
