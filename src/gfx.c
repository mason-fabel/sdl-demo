#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>

#include "globals.h"
#include "gfx.h"

bool gfx_init(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == 0) {
        fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == 0) {
        fprintf(stderr, "Unable to create renderer: %s\n", SDL_GetError());
        return false;
    }

    int img_flags = IMG_INIT_PNG;
    if (!(IMG_Init(img_flags) & img_flags)) {
        fprintf(stderr, "SDL_image could not initialize: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

SDL_Texture* gfx_load_texture(const char* path) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, path);
    if (texture == 0) {
        fprintf(stderr, "Unable to create texture: %s\n", SDL_GetError());
        return 0;
    }

    return texture;
}

void gfx_quit(void) {
    SDL_DestroyRenderer(renderer);
    renderer = 0;

    SDL_DestroyWindow(window);
    window = 0;

    IMG_Quit();
    SDL_Quit();
}
