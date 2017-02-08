#include <stdlib.h>
#include <string.h>

#include "cvar.h"

cvar_t *cvar_vars;

void cvar_set(char *name, char *value) {
	cvar_t	*var;

	var = cvar_findcvar(name);
	if (!var) {
		printf("cvar_set: variable %s not found\n", name);
		return;
	}

	free(var->string);

	var->string = malloc(strlen(value) + 1);
	strcpy_s(var->string, strlen(var->string), value);
	var->value = (float) atof(var->string);
}

cvar_t *cvar_findcvar(char *name) {
	cvar_t *var;

	for (var = cvar_vars; var; var = var->next)
		if (!strcmp(name, var->name))
			return var;

	return NULL;
}