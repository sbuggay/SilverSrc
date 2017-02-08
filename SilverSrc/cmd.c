#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmd.h"

typedef struct cmd_function_s {
	char *name;
	xfunction_t function;
	struct cmd_function_s *next;
} cmd_function_t;

static int cmd_argc;
static char *cmd_argv[CMD_MAX_ARGS];
static char *cmd_null_string = "";
static char	*cmd_args = 0;

static cmd_function_t *cmd_functions;

/**
* @brief Add a command to the list of cmd functions.
*
* Adds a command to the list of cmd functions. 
*/
void cmd_addcommand(char *cmd_name, xfunction_t function) {

	cmd_function_t *cmd;

	for (cmd = cmd_functions; cmd; cmd = cmd->next) {
		if (!strcmp(cmd_name, cmd->name)) {
			printf("cmd_addcommand: %s already defined\n", cmd_name);
			return;
		}
	}

	cmd = malloc(sizeof(cmd_function_t));
	cmd->name = cmd_name;
	cmd->function = function;
	cmd->next = cmd_functions;
	cmd_functions = cmd;
}

void cmd_execute(char *cmd_name) {
	cmd_function_t *cmd;
	for (cmd = cmd_functions; cmd; cmd = cmd->next) {
		if (!strcmp(cmd_name, cmd->name)) {
			// Invoke the command function
			printf("cmd running %s\n", cmd->name);
			cmd->function();
			return;
		}
	}
	printf("cmd none found with name %s\n", cmd_name);
	return;
}

//void cmd_tokenize(char *text) {
//
//	// Clear out old args
//	for (int i = 0; i < cmd_argc; i++)
//		free(cmd_argv[i]);
//
//	cmd_argc = 0;
//	cmd_args = NULL;
//
//	while (1)
//	{
//		// skip whitespace up to a /n
//		while (*text && *text <= ' ' && *text != '\n') {
//			text++;
//		}
//
//		if (*text == '\n') {
//			text++;
//			break;
//		}
//
//		if (!*text)
//			return;
//
//		if (cmd_argc == 1)
//			cmd_args = text;
//
//		text = COM_Parse(text);
//		if (!text)
//			return;
//
//		if (cmd_argc < CMD_MAX_ARGS) {
//			cmd_argv[cmd_argc] = Z_Malloc(Q_strlen(com_token) + 1);
//			Q_strcpy(cmd_argv[cmd_argc], com_token);
//			cmd_argc++;
//		}
//	}
//}