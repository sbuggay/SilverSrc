#include <stdio.h>

#include "vid.h"
#include "pak.h"
#include "common.h"
#include <string.h>


int main(int argc, char *argv[])
{
	com_init_param(argc, argv);
	

	pak_load("id1/pak0.pak");
	pak_load("id1/pak1.pak");

	// Set up palette
	uint8_t *buffer = NULL;
	pak_data("gfx/palette.lmp", &buffer);

	memcpy(&vid_palette, buffer, sizeof(pakpalette_t));


	pakpicture_t *finale = pak_load_pic("gfx/finale.lmp");



	vid_init();

	int i;
	for (i = 0; i < num_display_modes; i++)
	{
		SDL_DisplayMode mode = display_modes[i];
		printf("%i:\t%ix%i\t%dhz\t%i bpp\n", i, mode.w, mode.h, mode.refresh_rate, SDL_BITSPERPIXEL(mode.format));
	}


	SDL_Event event;

	int quit = 0;

	while (!quit)
	{

		Uint32 flags = (SDL_GetWindowFlags(window) ^ SDL_WINDOW_FULLSCREEN);
		while (SDL_PollEvent(&event))
		{

			switch (event.type)
			{
			case SDL_QUIT:
				quit = 1;
				break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym)
				{
				case SDLK_1:
					
					SDL_SetWindowFullscreen(window, flags);
					break;
				case SDLK_2:
					break;
				case SDLK_3:
					break;
				case SDLK_4:
					break;
				}
				break;
			}

			
		}

		vid_draw_pic(*finale, 20, 20);

		SDL_RenderPresent(renderer);
	}

	free(finale);

	vid_quit();

	return 0;
}
