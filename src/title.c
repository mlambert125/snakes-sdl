#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include "../includes/scenes.h"
#include "../includes/textures.h"

Scene sceneTitleScreen(GameState *state, SDL_Window *window,
                    SDL_Renderer *renderer, SDL_Event *event) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, title, nullptr, nullptr);

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
            case SDLK_q:
                Scene retQuit = {true, nullptr};
                return retQuit;
            case SDLK_RETURN:
                *state = getInitialGameState();
                updateScoreTexture(state, renderer);
                updateLivesTexture(state, renderer);
                Scene retGame = {false, sceneGame};
                return retGame;
            }
        }
    }

    Scene retMenu = {false, sceneTitleScreen};
    return retMenu;
}
