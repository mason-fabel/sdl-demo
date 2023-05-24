#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <SDL.h>
#include "SDL_render.h"
#include "globals.h"
#include "gfx.h"

const uint32_t SCREEN_WIDTH = 400;
const uint32_t SCREEN_HEIGHT = 300;

SDL_Window* window = 0;
SDL_Renderer* renderer = 0;
//SDL_Surface* screenSurface = 0;
//

enum game_state {
    GAME_STATE_LOADING,
    GAME_STATE_RUNNING,
    GAME_STATE_QUITTING
};
typedef enum game_state game_state;

int main(void) {
    game_state state = GAME_STATE_LOADING;

    if (!gfx_init()) {
        return EXIT_FAILURE;
    }

    SDL_Texture* texture = gfx_load_texture("assets/wolf3d_redbrick.png");
    if (texture == 0){
        fprintf(stderr, "Unable to load texture assets/wolf3d_redbrick.png\n");
        return EXIT_FAILURE;
    }

    state = GAME_STATE_RUNNING;
    while (state == GAME_STATE_RUNNING) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                state = GAME_STATE_QUITTING;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);

        SDL_Rect fill_rect = {
            .x = SCREEN_WIDTH / 4,
            .y = SCREEN_HEIGHT / 4,
            .w = SCREEN_WIDTH / 2,
            .h = SCREEN_HEIGHT / 2,
        };
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &fill_rect);

        SDL_Rect texture_position = {
            .x = 0,
            .y = 0,
            .w = SCREEN_HEIGHT / 2,
            .h = SCREEN_HEIGHT / 2,
        };
        SDL_RenderCopy(renderer, texture, 0, &texture_position);

        SDL_Rect outline_rect = {
            .x = SCREEN_WIDTH / 6,
            .y = SCREEN_HEIGHT / 6,
            .w = SCREEN_WIDTH * 2 / 3,
            .h = SCREEN_HEIGHT * 2 / 3,
        };
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawRect(renderer, &outline_rect);

        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
        for(uint32_t i = 0; i < SCREEN_HEIGHT; i += 4)
        {
            SDL_RenderDrawPoint(renderer, i, i);
        }


        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    texture = 0;

    gfx_quit();

    return EXIT_SUCCESS;
}
