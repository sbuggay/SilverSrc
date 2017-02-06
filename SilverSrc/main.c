#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vid.h"
#include "pak.h"
#include "keys.h"
#include "common.h"
#include "cmd.h"

int main(int argc, char *argv[]) {

	com_init_param(argc, argv);

	pak_load("id1/pak0.pak");
	pak_load("id1/pak1.pak");

	// Set up palette
	uint8_t *buffer = NULL;
	pak_data("gfx/palette.lmp", &buffer);

	memcpy(&vid_palette, buffer, sizeof(pakpalette_t));

	pakpicture_t *finale = pak_load_pic("gfx/conback.lmp");

	// Are these needed?
	atexit(SDL_Quit);
	
	vid_init();

	SDL_Event event;
	int quit = 0;

	while (!quit) {

		Uint32 flags = (SDL_GetWindowFlags(window) ^ SDL_WINDOW_FULLSCREEN);
		while (SDL_PollEvent(&event)) {

			switch (event.type) {
			case SDL_QUIT:
				quit = 1;
				break;
			case SDL_KEYDOWN:
				key_console(event.key.keysym.sym);
				break;
			}
		}

		vid_draw_pic(*finale, 0, 0);
		SDL_RenderPresent(renderer);
	}

	free(finale);
	vid_quit();

	return 0;
}
