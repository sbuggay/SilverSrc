#pragma once
#include <SDL.h>
#include "pak.h"

SDL_Window *window;
SDL_Renderer *renderer;

int num_display_modes;
SDL_DisplayMode *display_modes;

pakpalette_t vid_palette;

int vid_init();
int vid_quit();
int vid_set_display_mode(int mode);

void vid_draw_pic(pakpicture_t pic, int x, int y);

