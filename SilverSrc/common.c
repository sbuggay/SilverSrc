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