#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <stdio.h>
#include "../includes/init.h"
#include "../includes/scenes.h"
#include "../includes/state.h"
#include "../includes/textures.h"

#define FPS 10

int main() {
    GameState gameState;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    Scene currentScene = {false, sceneTitleScreen};

    if (!initSdl(&window, &renderer)) {
        fprintf(stderr, "Failed to initialize\n");
        return 1;
    }
    if (!loadTextures(renderer)) {
        fprintf(stderr, "Failed to load textures\n");
        return 1;
    }

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        currentScene = currentScene.scene_fn(&gameState, window, renderer, &e);
        if (currentScene.quit) {
            quit = true;
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / FPS);
    }

    if (!freeTextures()) {
        fprintf(stderr, "Failed to free textures\n");
    }
    sdlClose(&window, &renderer);
    return 0;
}
