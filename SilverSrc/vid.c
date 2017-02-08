#include <string.h>
#include <stdio.h>

#include "vid.h"
#include "common.h"

int vid_init() {

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	window = SDL_CreateWindow("SilverSrc", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480, SDL_WINDOW_OPENGL);

	if (window == NULL) return -1;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	int display_count = 0, display_index = 0, mode_index = 0;

	if ((display_count = SDL_GetNumVideoDisplays()) < 1) {
		SDL_Log("SDL_GetNumVideoDisplays returned: %i", display_count);
	}

	num_display_modes = SDL_GetNumDisplayModes(display_index);
	display_modes = malloc(num_display_modes * sizeof(SDL_DisplayMode));

	for (mode_index = 0; mode_index < num_display_modes; mode_index++) {
		SDL_DisplayMode mode = { SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, 0 };
		SDL_GetDisplayMode(display_index, mode_index, &mode);
		display_modes[mode_index] = mode;
	}

	return 0;
}

int vid_quit() {
	SDL_DestroyWindow(window);
	free(display_modes);
	SDL_Quit();

	return 0;
}

int vid_set_display_mode(int mode) {
	if (mode < 0 || mode >= num_display_modes) return -1;

	SDL_SetWindowDisplayMode(window, &display_modes[mode]);

	return 1;
}

void vid_render() {
	SDL_RenderPresent(renderer);
}

void vid_set_palette() {

}

void vid_draw_pixel(int index, int x, int y) {
	SDL_SetRenderDrawColor(renderer, vid_palette[index].red, vid_palette[index].green, vid_palette[index].blue, 0xFF);
	SDL_RenderDrawPoint(renderer, x, y);
}

void vid_draw_pic(pakpicture_t pic, int x, int y) {
	uint8_t *pixel = pic.data;
	unsigned int i, j;
	for (j = 0; j < pic.height; j++)
	{
		for (i = 0; i < pic.width; i++)
		{
			vid_draw_pixel(*pixel, x + i, y + j);
			pixel++;
		}
	}
}