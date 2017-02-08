#include <SDL_mixer.h>

#include "audio.h"

int audio_init() {
	int ret = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 4096);
	return ret;
}

void audio_play(uint8_t *data) {
	Mix_Chunk *chunk = Mix_QuickLoad_WAV(data);
	int channel = Mix_PlayChannel(-1, chunk, 0);
	Mix_FreeChunk(chunk);
	chunk = NULL;
}