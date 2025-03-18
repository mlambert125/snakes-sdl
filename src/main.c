#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <stdio.h>
#include "../includes/init.h"
#include "../includes/scenes.h"
#include "../includes/state.h"
#include "../includes/textures.h"

#define FPS 20

int main() {
    GameState gameState;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    Scene currentScene = {false, sceneTitleScreen};

    if (!initSdl(&window, &renderer)) {
        fprintf(stderr, "Failed to initialize\n");
        return 1;
    }
    if (!loadTextures(renderer)) {
        fprintf(stderr, "Failed to load textures\n");
        return 1;
    }

    while (!currentScene.quit) {
        currentScene = currentScene.scene_fn(&gameState, renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / FPS);
    }

    if (!freeTextures()) {
        fprintf(stderr, "Failed to free textures\n");
    }

    sdlClose(&window, &renderer);
    return 0;
}
