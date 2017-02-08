#include "common.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void com_init_param(int argc, char *argv[])
{
	num_params = argc;
	com_params = argv;
}

int com_check_param(char *param)
{
	int i = 0;
	for (i; i < num_params; i++)
	{
		if (strcmp(com_params[i], param) == 0) return 1;
	}
	return 0;
}

//char **com_parse(char *data) {
//	int c, len = 0;
//
//	char **com_token;
//
//	if (!data) return NULL;
//
//	// skip whitespace
//skipwhite:
//	while ((c = *data) <= ' ') {
//		if (c == 0) return NULL;
//		data++;
//	}
//
//	// skip // comments
//	if (c == '/' && data[1] == '/') {
//		while (*data && *data != '\n')
//			data++;
//		goto skipwhite;
//	}
//
//
//	// handle quoted strings specially
//	if (c == '\"') {
//		data++;
//		while (1) {
//			c = *data++;
//			if (c == '\"' || !c) {
//				com_token[len] = 0;
//				return data;
//			}
//			com_token[len] = c;
//			len++;
//		}
//	}
//
//	// parse single characters
//	if (c == '{' || c == '}' || c == ')' || c == '(' || c == '\'' || c == ':') {
//		com_token[len] = c;
//		len++;
//		com_token[len] = 0;
//		return data + 1;
//	}
//
//	// parse a regular word
//	do {
//		com_token[len] = c;
//		data++;
//		len++;
//		c = *data;
//		if (c == '{' || c == '}' || c == ')' || c == '(' || c == '\'' || c == ':')
//			break;
//	} while (c > 32);
//
//	com_token[len] = 0;
//	return data;
//}