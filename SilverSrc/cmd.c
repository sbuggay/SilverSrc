#include <stdlib.h>
#include <string.h>

#include "cmd.h"

typedef struct cmd_function_s {
	char *name;
	xfunction_t *function;
	struct cmd_function_s *next;
} cmd_function_t;

static int cmd_argc;
static char *cmd_argv[CMD_MAX_ARGS];
static char *cmd_null_string = "";
static char	*cmd_args = 0;

static cmd_function_t *cmd_functions;

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

	int x = 0;
}