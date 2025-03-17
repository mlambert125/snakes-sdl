#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "../includes/init.h"

bool initSdl(SDL_Window **window, SDL_Renderer **screenRenderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return false;
    }
    if (TTF_Init() == -1) {
        fprintf(stderr, "SDL_ttf could not initialize! SDL_ttf Error: %s\n",
                TTF_GetError());
        return false;
    }
    *window =
        SDL_CreateWindow("Snakes!", SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    if (*window == nullptr) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return false;
    }

    *screenRenderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    return true;
}

void sdlClose(SDL_Window **window, SDL_Renderer **screenRenderer) {
    SDL_DestroyRenderer(*screenRenderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}
