#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../includes/textures.h"
#include "../includes/state.h"

SDL_Texture* title = NULL;
SDL_Texture* gameOver = NULL;
SDL_Texture* snakeSquare = NULL;
SDL_Texture* scoreText = NULL;
SDL_Texture* livesText = NULL;
SDL_Texture* wall = NULL;
SDL_Texture* apple = NULL;

bool loadTextures(SDL_Renderer *renderer) {
    if (title == NULL) {
        SDL_Surface *surface = SDL_LoadBMP("resources/title.bmp");
        if (surface == NULL) {
            fprintf(stderr, "Failed to load title texture: %s\n", SDL_GetError());
            return false;
        }
        title = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    if (gameOver == NULL) {
        SDL_Surface *surface = SDL_LoadBMP("resources/gameover.bmp");
        if (surface == NULL) {
            fprintf(stderr, "Failed to load game over texture: %s\n", SDL_GetError());
            return false;
        }
        gameOver = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    if (snakeSquare == NULL) {
        SDL_Surface *surface = SDL_CreateRGBSurface(0, 20, 20, 32, 0, 0, 0, 0);
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0xFF, 0x00));
        snakeSquare = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    if (wall == NULL) {
        SDL_Surface *surface = SDL_LoadBMP("resources/wall.bmp");
        if (surface == NULL) {
            fprintf(stderr, "Failed to load wall texture: %s\n", SDL_GetError());
            return false;
        }
        wall = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    if (apple == NULL) {
        SDL_Surface *surface = SDL_LoadBMP("resources/apple.bmp");
        if (surface == NULL) {
            fprintf(stderr, "Failed to load apple texture: %s\n", SDL_GetError());
            return false;
        }
        apple = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    if (scoreText == NULL) {
        TTF_Font *font = TTF_OpenFont("resources/DejaVuSans.ttf", 12);
        if (font == NULL) {
            fprintf(stderr, "Failed to load font: %s\n", TTF_GetError());
            return false;
        }
        SDL_Color color = (SDL_Color){255, 255, 255, 255};
        SDL_Surface *surface = TTF_RenderText_Solid(font, "Score: 0", color);
        scoreText = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
    }
    if (livesText == NULL) {
        TTF_Font *font = TTF_OpenFont("resources/DejaVuSans.ttf", 36);
        if (font == NULL) {
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
    if (scoreText != NULL) {
        SDL_DestroyTexture(scoreText);
        scoreText = NULL;
    }
    TTF_Font *font = TTF_OpenFont("resources/DejaVuSans.ttf", 36);
    if (font == NULL) {
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
    if (scoreText == NULL) {
        fprintf(stderr, "Failed to create score texture: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool updateLivesTexture(GameState *state, SDL_Renderer *renderer) {
    if (livesText != NULL) {
        SDL_DestroyTexture(livesText);
        livesText = NULL;
    }
    TTF_Font *font = TTF_OpenFont("resources/DejaVuSans.ttf", 24);
    if (font == NULL) {
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
    if (livesText == NULL) {
        fprintf(stderr, "Failed to create lives texture: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool freeTextures() {
    if (title != NULL) {
        SDL_DestroyTexture(title);
        title = NULL;
    }
    if (gameOver != NULL) {
        SDL_DestroyTexture(gameOver);
        gameOver = NULL;
    }
    if (snakeSquare != NULL) {
        SDL_DestroyTexture(snakeSquare);
        snakeSquare = NULL;
    }
    if (scoreText != NULL) {
        SDL_DestroyTexture(scoreText);
        scoreText = NULL;
    }
    if (wall != NULL) {
        SDL_DestroyTexture(wall);
        wall = NULL;
    }
    if (apple != NULL) {
        SDL_DestroyTexture(apple);
        apple = NULL;
    }
    if (livesText != NULL) {
        SDL_DestroyTexture(livesText);
        livesText = NULL;
    }
    return true;
}

