#pragma once

#include <stdbool.h>
#include <SDL.h>

bool gfx_init(void);
SDL_Texture* gfx_load_texture(const char* path);
void gfx_quit(void);
