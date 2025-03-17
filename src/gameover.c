#include <SDL2/SDL.h>
#include "../includes/scenes.h"
#include "../includes/textures.h"

Scene sceneGameOver(GameState *state, SDL_Window *window,
                    SDL_Renderer *renderer, SDL_Event *event) {

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, gameOver, nullptr, nullptr);
    
    while (SDL_PollEvent(event) != 0) {
        if (event->type == SDL_KEYDOWN) {
            switch (event->key.keysym.sym) {
            case SDLK_ESCAPE:
            case SDLK_q:
                return (Scene){true, nullptr};
            }
        }
    }

    if (state->gameOverFramesDisplayed < 30) {
        state->gameOverFramesDisplayed++;
        return (Scene){false, sceneGameOver};
    } else {
        state->gameOverFramesDisplayed = 0;
        return (Scene){false, sceneTitleScreen};
    }
}
