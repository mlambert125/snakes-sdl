#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../includes/textures.h"
#include "../includes/state.h"

static const char titleBmp[] = {
#embed "../resources/title.bmp"
};

static const char gameOverBmp[] = {
#embed "../resources/gameover.bmp"
};

static const char wallBmp[] = {
#embed "../resources/wall.bmp"
};

static const char appleBmp[] = {
#embed "../resources/apple.bmp"
};

static const char DejaVuSansTtf[] = {
#embed "../resources/DejaVuSans.ttf"
};

SDL_Texture *title = nullptr;
SDL_Texture *gameOver = nullptr;
SDL_Texture *snakeSquare = nullptr;
SDL_Texture *scoreText = nullptr;
SDL_Texture *livesText = nullptr;
SDL_Texture *wall = nullptr;
SDL_Texture *apple = nullptr;

SDL_Texture *loadTexture(const char *bmp, int size, SDL_Renderer *renderer);

bool loadTextures(SDL_Renderer *renderer) {

    title = loadTexture(titleBmp, sizeof(titleBmp), renderer);
    if (title == nullptr) {
        fprintf(stderr, "Failed to load title texture\n");
        return false;
    }
    gameOver = loadTexture(gameOverBmp, sizeof(gameOverBmp), renderer);
    if (gameOver == nullptr) {
        fprintf(stderr, "Failed to load game over texture\n");
        return false;
    }
    wall = loadTexture(wallBmp, sizeof(wallBmp), renderer);
    if (wall == nullptr) {
        fprintf(stderr, "Failed to load wall texture\n");
        return false;
    }
    apple = loadTexture(appleBmp, sizeof(appleBmp), renderer);
    if (apple == nullptr) {
        fprintf(stderr, "Failed to load apple texture\n");
        return false;
    }

    {
        SDL_Surface *surface = SDL_CreateRGBSurface(0, 20, 20, 32, 0, 0, 0, 0);
        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0x00, 0xFF, 0x00));
        snakeSquare = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    {
        TTF_Font *font = TTF_OpenFontRW(SDL_RWFromConstMem(DejaVuSansTtf, sizeof(DejaVuSansTtf)), 1, 36);
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

    {
        TTF_Font *font = TTF_OpenFontRW(SDL_RWFromConstMem(DejaVuSansTtf, sizeof(DejaVuSansTtf)), 1, 36);
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

SDL_Texture *loadTexture(const char *bmp, int size, SDL_Renderer *renderer) {
    SDL_Surface *surface = SDL_LoadBMP_RW(SDL_RWFromConstMem(bmp, size), 1);
    if (surface == nullptr) {
        fprintf(stderr, "Failed to load texture: %s\n", SDL_GetError());
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
