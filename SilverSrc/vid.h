#pragma once
#include <SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

int num_display_modes;
SDL_DisplayMode *display_modes;

// color_map 

int vid_init();
int vid_quit();
int vid_set_display_mode(int mode);

