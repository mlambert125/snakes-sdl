#include <SDL2/SDL.h>
#include <stdlib.h>
#include "../includes/scenes.h"
#include "../includes/textures.h"

inline void resetAppleLocation(GameState *state);

Scene sceneGame(GameState *state, SDL_Window *window, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    for (int i = 0; i < MAX_X; i++) {
        SDL_RenderCopy(renderer, wall, nullptr, &(SDL_Rect){i * 20, 0, 20, 20});
        SDL_RenderCopy(renderer, wall, nullptr, &(SDL_Rect){i * 20, (MAX_Y - 1) * 20, 20, 20});
    }

    for (int i = 0; i < MAX_Y; i++) {
        SDL_RenderCopy(renderer, wall, nullptr, &(SDL_Rect){0, i * 20, 20, 20});
        SDL_RenderCopy(renderer, wall, nullptr, &(SDL_Rect){(MAX_X - 1) * 20, i * 20, 20, 20});
    }

    for (int i = 0; i < state->snakeLength; i++) {
        SDL_RenderCopy(renderer, snakeSquare, nullptr,
                       &(SDL_Rect){state->snakeBodySegmentLocations[i].x * 20,
                                   state->snakeBodySegmentLocations[i].y * 20, 20, 20});
    }
    SDL_RenderCopy(renderer, apple, nullptr,
                   &(SDL_Rect){state->appleLocation.x * 20, state->appleLocation.y * 20, 20, 20});

    SDL_RenderCopy(renderer, scoreText, nullptr, &(SDL_Rect){150, 0, 100, 30});
    SDL_RenderCopy(renderer, livesText, nullptr, &(SDL_Rect){300, 0, 100, 30});

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
            case SDLK_q:
                return (Scene){true, nullptr};

            case SDLK_LEFT:
            case SDLK_a:
                if (state->snakeDirection != RIGHT) state->snakeDirection = LEFT;
                break;

            case SDLK_RIGHT:
            case SDLK_d:
                if (state->snakeDirection != LEFT) state->snakeDirection = RIGHT;
                break;

            case SDLK_UP:
            case SDLK_w:
                if (state->snakeDirection != DOWN) state->snakeDirection = UP;
                break;

            case SDLK_DOWN:
            case SDLK_s:
                if (state->snakeDirection != UP) state->snakeDirection = DOWN;
                break;
            }
        }
    }

    for (int i = state->snakeLength - 1; i > 0; i--) {
        state->snakeBodySegmentLocations[i] = state->snakeBodySegmentLocations[i - 1];
    }

    switch (state->snakeDirection) {
    case LEFT:
        state->snakeBodySegmentLocations[0].x -= 1;
        break;

    case RIGHT:
        state->snakeBodySegmentLocations[0].x += 1;
        break;

    case UP:
        state->snakeBodySegmentLocations[0].y -= 1;
        break;

    case DOWN:
        state->snakeBodySegmentLocations[0].y += 1;
        break;
    }

    if (state->snakeBodySegmentLocations[0].x == state->appleLocation.x &&
        state->snakeBodySegmentLocations[0].y == state->appleLocation.y) {

        state->score += 1;
        resetAppleLocation(state);
        state->snakeLength += 1;
        if (state->snakeLength > MAX_SNAKE_LENGTH) {
            state->snakeLength = MAX_SNAKE_LENGTH;
        }
        state->snakeBodySegmentLocations[state->snakeLength - 1] =
            state->snakeBodySegmentLocations[state->snakeLength - 2];
        updateScoreTexture(state, renderer);
    }

    if (state->snakeBodySegmentLocations[0].x < 1 || state->snakeBodySegmentLocations[0].x >= MAX_X - 1 ||
        state->snakeBodySegmentLocations[0].y < 1 || state->snakeBodySegmentLocations[0].y >= MAX_Y - 1) {
        state->lives -= 1;
        updateLivesTexture(state, renderer);
        state->snakeLength = 1;
        state->snakeBodySegmentLocations[0].x = (MAX_X + 1) / 2;
        state->snakeBodySegmentLocations[0].y = (MAX_Y + 1) / 2;
        state->snakeDirection = UP;
        resetAppleLocation(state);

        if (state->lives == 0) {
            return (Scene){false, sceneGameOver};
        }
    }

    return (Scene){false, sceneGame};
}

void resetAppleLocation(GameState *state) {
    state->appleLocation.x = rand() % (MAX_X - 2) + 1;
    state->appleLocation.y = rand() % (MAX_Y - 2) + 1;
}
