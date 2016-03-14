#include <stdio.h>
#include <string.h>

#include <SDL_mixer.h>

#include "vid.h"
#include "pak.h"
#include "common.h"

int main(int argc, char *argv[])
{
	com_init_param(argc, argv);
	

	pak_load("id1/pak0.pak");

	palette pal;
	memcpy(&pal, pak_data("gfx/palette.lmp"), sizeof(pal));


	vid_init();

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}

	int i;
	for (i = 0; i < num_display_modes; i++)
	{
		SDL_DisplayMode mode = display_modes[i];
		printf("%i:\t%ix%i\t%dhz\t%i bpp\n", i, mode.w, mode.h, mode.refresh_rate, SDL_BITSPERPIXEL(mode.format));
	}

//	vid_set_display_mode(16);

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

		SDL_Rect rect = { 0, 0, 30, 30 };

		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}


	vid_quit();

	return 0;
}
