#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <SDL.h>
#include "globals.h"
#include "init.h"

const uint32_t SCREEN_WIDTH = 400;
const uint32_t SCREEN_HEIGHT = 300;

SDL_Window* window = 0;
SDL_Surface* screenSurface = 0;

int main(void) {
    if (!init_sdl()) {
        return EXIT_FAILURE;
    }

    SDL_Surface* image = 0;
    if ((image = init_load_surface("./resources/wolf3d_redbrick.png")) == 0) {
        return EXIT_FAILURE;
    }

    SDL_Rect image_stretch_rect = {
        .x = 0,
        .y = 0,
        .h = SCREEN_HEIGHT,
        .w = SCREEN_HEIGHT,
    };

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_BlitScaled(image, 0, screenSurface, &image_stretch_rect);

        SDL_UpdateWindowSurface(window);
    }

    SDL_FreeSurface(image);
    image = 0;

    if (!init_quit()) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
