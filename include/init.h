#pragma once

#include <stdbool.h>
#include <SDL.h>

bool init_sdl(void);
SDL_Surface* init_load_surface(const char* path);
SDL_Surface* init_xor_surface(void);
bool init_quit(void);
