#pragma once

typedef struct cvar_s {
	char *name;
	char *string;
	float value;
	struct cvar_s *next;
} cvar_t;

void cvar_set(char *name, char *value);
cvar_t *cvar_findcvar(char *name);