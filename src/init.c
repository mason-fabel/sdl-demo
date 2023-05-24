#include <stdbool.h>
#include <SDL.h>

#include "globals.h"
#include "init.h"

bool init_sdl(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == 0) {
        fprintf(stderr, "Window could not be created: %s\n", SDL_GetError());
        return false;
    }

    screenSurface = SDL_GetWindowSurface(window);
    if (screenSurface == 0) {
        fprintf(stderr, "Could not get window surface: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

SDL_Surface* init_load_surface(const char* path) {
    SDL_Surface* raw_surface = SDL_LoadBMP(path);
    if (raw_surface == 0) {
        fprintf(stderr, "Unable to load image: %s\n", SDL_GetError());
        return 0;
    }

    SDL_Surface* optimized_surface = SDL_ConvertSurface(raw_surface, screenSurface->format, 0);
    if (optimized_surface == 0) {
        fprintf(stderr, "Unable to optimize image: %s\n", SDL_GetError());
        return 0;
    }

    SDL_FreeSurface(raw_surface);

    return optimized_surface;
}

SDL_Surface* init_xor_surface(void) {
    const uint8_t DIM = 64;

    for (uint8_t x = 0; x < DIM; x++) {
        for (uint8_t y = 0; y < DIM; y++) {
        }
    }

    return 0;
}

bool init_quit(void) {

    SDL_DestroyWindow(window);
    window = 0;

    SDL_Quit();

    return true;
}
