#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vid.h"
#include "draw.h"
#include "audio.h"
#include "pak.h"
#include "keys.h"
#include "common.h"
#include "cmd.h"
#include "test.h"

int main(int argc, char *argv[]) {

	test_init();

	com_init_param(argc, argv);

	pak_load("id1/pak0.pak");
	pak_load("id1/pak1.pak");

	// Set up palette
	uint8_t *buffer = NULL;
	pak_data("gfx/palette.lmp", &buffer);

	memcpy(&vid_palette, buffer, sizeof(pakpalette_t));

	pakpicture_t *finale = pak_load_pic("gfx/conback.lmp");
	
	uint8_t *audiotest = NULL;
	pak_data("sound/doors/medtry.wav", &audiotest);

	vid_init();
	audio_init();

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
				audio_play(audiotest);
				break;
			}
		}

		vid_draw_pic(*finale, 0, 0);
		vid_render();
	}

	free(finale);
	vid_quit();

	return 0;
}
