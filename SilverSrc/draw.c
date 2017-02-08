#include <stdint.h>

#include <SDL_ttf.h>
#include "vid.h"
#include "draw.h"

void draw_character(int x, int y, int num)
{
	
}

void draw_string(int x, int y, char *text) {
	TTF_Init();

	TTF_Font* quake = TTF_OpenFont("quake.ttf", 24);
	SDL_Color white = { 255, 255, 255 };
	SDL_Surface *text_surface = TTF_RenderText_Solid(quake, text, white);
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

	SDL_Rect text_rect;
	text_rect.x = x;
	text_rect.y = y;
	text_rect.w = 1000;
	text_rect.h = 100;

	SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
}