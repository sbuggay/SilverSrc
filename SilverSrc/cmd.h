#pragma once

#define CMD_MAX_ARGS 80

typedef void(*xfunction_t) (void);

void cmd_addcommand(char *cmd_name, xfunction_t function);
void cmd_execute(char *cmd_name);
void cmd_tokenize(char *command);