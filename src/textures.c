#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../includes/textures.h"
#include "../includes/state.h"

SDL_Texture *title = nullptr;
SDL_Texture *gameOver = nullptr;
SDL_Texture *snakeSquare = nullptr;
SDL_Texture *scoreText = nullptr;
SDL_Texture *livesText = nullptr;
SDL_Texture *wall = nullptr;
SDL_Texture *apple = nullptr;

bool loadTextures(SDL_Renderer *renderer) {
    if (title == nullptr) {
        SDL_Surface *surface = SDL_LoadBMP("resources/title.bmp");
        if (surface == nullptr) {
            fprintf(stderr, "Failed to load title texture: %s\n", SDL_GetError());
            return false;
        }
        title = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    if (gameOver == nullptr) {
        SDL_Surface *surface = SDL_LoadBMP("resources/gameover.bmp");
        if (surface == nullptr) {
            fprintf(stderr, "Failed to load game over texture: %s\n", SDL_GetError());
            return false;
        }
        gameOver = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    if (snakeSquare == nullptr) {
        SDL_Surface *surface = SDL_CreateRGBSurface(0, 20, 20, 32, 0, 0, 0, 0);
        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0x00, 0xFF, 0x00));
        snakeSquare = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    if (wall == nullptr) {
        SDL_Surface *surface = SDL_LoadBMP("resources/wall.bmp");
        if (surface == nullptr) {
            fprintf(stderr, "Failed to load wall texture: %s\n", SDL_GetError());
            return false;
        }
        wall = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    if (apple == nullptr) {
        SDL_Surface *surface = SDL_LoadBMP("resources/apple.bmp");
        if (surface == nullptr) {
            fprintf(stderr, "Failed to load apple texture: %s\n", SDL_GetError());
            return false;
        }
        apple = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    if (scoreText == nullptr) {
        TTF_Font *font = TTF_OpenFont("resources/DejaVuSans.ttf", 12);
        if (font == nullptr) {
            fprintf(stderr, "Failed to load font: %s\n", TTF_GetError());
            return false;
        }
        SDL_Color color = (SDL_Color){255, 255, 255, 255};
        SDL_Surface *surface = TTF_RenderText_Solid(font, "Score: 0", color);
        scoreText = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
    }

    if (livesText == nullptr) {
        TTF_Font *font = TTF_OpenFont("resources/DejaVuSans.ttf", 36);
        if (font == nullptr) {
            fprintf(stderr, "Failed to load font: %s\n", TTF_GetError());
            return false;
        }
        SDL_Color color = (SDL_Color){255, 255, 255, 255};
        SDL_Surface *surface = TTF_RenderText_Solid(font, "Lives: 3", color);
        livesText = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
    }
    return true;
}

bool updateScoreTexture(GameState *state, SDL_Renderer *renderer) {
    if (scoreText != nullptr) {
        SDL_DestroyTexture(scoreText);
        scoreText = nullptr;
    }

    TTF_Font *font = TTF_OpenFont("resources/DejaVuSans.ttf", 36);
    if (font == nullptr) {
        fprintf(stderr, "Failed to load font: %s\n", TTF_GetError());
        return false;
    }

    char scoreTextBuffer[32];
    snprintf(scoreTextBuffer, sizeof(scoreTextBuffer), "Score: %d", state->score);
    SDL_Color color = (SDL_Color){255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, scoreTextBuffer, color);
    scoreText = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    if (scoreText == nullptr) {
        fprintf(stderr, "Failed to create score texture: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool updateLivesTexture(GameState *state, SDL_Renderer *renderer) {
    if (livesText != nullptr) {
        SDL_DestroyTexture(livesText);
        livesText = nullptr;
    }
    TTF_Font *font = TTF_OpenFont("resources/DejaVuSans.ttf", 24);
    if (font == nullptr) {
        fprintf(stderr, "Failed to load font: %s\n", TTF_GetError());
        return false;
    }

    char livesTextBuffer[32];
    snprintf(livesTextBuffer, sizeof(livesTextBuffer), "Lives: %d", state->lives);
    SDL_Color color = (SDL_Color){255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, livesTextBuffer, color);
    livesText = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    if (livesText == nullptr) {
        fprintf(stderr, "Failed to create lives texture: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool freeTextures() {
    if (title != nullptr) {
        SDL_DestroyTexture(title);
        title = nullptr;
    }

    if (gameOver != nullptr) {
        SDL_DestroyTexture(gameOver);
        gameOver = nullptr;
    }

    if (snakeSquare != nullptr) {
        SDL_DestroyTexture(snakeSquare);
        snakeSquare = nullptr;
    }

    if (scoreText != nullptr) {
        SDL_DestroyTexture(scoreText);
        scoreText = nullptr;
    }

    if (wall != nullptr) {
        SDL_DestroyTexture(wall);
        wall = nullptr;
    }

    if (apple != nullptr) {
        SDL_DestroyTexture(apple);
        apple = nullptr;
    }

    if (livesText != nullptr) {
        SDL_DestroyTexture(livesText);
        livesText = nullptr;
    }

    return true;
}
