#pragma once

#define MAX_PARAMS 256
#define MAX_PARAM_LENGTH 256

int num_params;
char **com_params;

void com_init_param(int argc, char *argv[]);
int com_check_param(char *param);