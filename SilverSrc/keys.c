#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#include "keys.h"

char key_input[MAXCMDLINE] = { 0 };
int key_linepos = 0;

char keydown[256];

void key_console(char key) {

	if (key == SDLK_RETURN) {
		printf("return\n");
		key_linepos = 0;
		memset(key_input, 0, MAXCMDLINE);
	}
	
	if (key < 32 || key > 127) return;

	if (key_linepos < MAXCMDLINE - 1) {
		key_input[key_linepos++] = key;
		key_input[key_linepos] = 0;
		printf("%s\n", key_input);
	}
}