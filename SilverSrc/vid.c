

#include "vid.h"
#include "common.h"

int vid_init()
{

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"SilverSrc",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
		);

	if (window == NULL) {
		return -1;
	}

	if(!com_check_param("-sw"))
		SDL_SetWindowFullscreen(window, 0);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	int display_count = 0, display_index = 0, mode_index = 0;
	

	if ((display_count = SDL_GetNumVideoDisplays()) < 1) {
		SDL_Log("SDL_GetNumVideoDisplays returned: %i", display_count);
	}

	num_display_modes = SDL_GetNumDisplayModes(display_index);
	display_modes = malloc(num_display_modes * sizeof(SDL_DisplayMode));

	for (mode_index = 0; mode_index < num_display_modes; mode_index++)
	{
		SDL_DisplayMode mode = { SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, 0 };
		SDL_GetDisplayMode(display_index, mode_index, &mode);
		display_modes[mode_index] = mode;
	}

	return 0;
}

int vid_quit()
{

	SDL_DestroyWindow(window);
	
	free(display_modes);

	SDL_Quit();

	return 0;
}

int vid_set_display_mode(int mode)
{
	if (mode < 0 || mode >= num_display_modes) return -1;

	SDL_SetWindowDisplayMode(window, &display_modes[mode]);

	return 1;
}

void vid_draw_pic(pakpicture_t pic, int x, int y)
{
	unsigned char *pixel = pic.data;
	int i, j;
	for (j = 0; j < pic.height; j++)
	{
		for (i = 0; i < pic.width; i++)
		{
			SDL_SetRenderDrawColor(renderer, palette[*pixel].red, palette[*pixel].green, palette[*pixel].blue, 0xFF);
			SDL_RenderDrawPoint(renderer, x + i, y + j);
			pixel++;
		}
	}
}