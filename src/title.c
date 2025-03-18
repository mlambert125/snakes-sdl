#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include "../includes/scenes.h"
#include "../includes/textures.h"

Scene sceneTitleScreen(GameState *state, SDL_Window *window, SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, title, nullptr, nullptr);

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
            case SDLK_q:
                return (Scene){true, nullptr};

            case SDLK_RETURN:
                *state = getInitialGameState();
                updateScoreTexture(state, renderer);
                updateLivesTexture(state, renderer);
                return (Scene){false, sceneGame};
            }
        }
    }

    return (Scene){false, sceneTitleScreen};
}
