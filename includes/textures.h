#ifndef TEXTURES_H
#define TEXTURES_H
#include <SDL2/SDL.h>
#include "../includes/state.h"

/**
 * The texture for the title screen.
 */
extern SDL_Texture *title;

/**
 * The texture for the game over screen.
 */
extern SDL_Texture *gameOver;

/**
 * The texture for the apple.
 */
extern SDL_Texture *apple;

/**
 * The texture for the snake square.
 */
extern SDL_Texture *snakeSquare;

/**
 * The texture for the wall.
 */
extern SDL_Texture *wall;

/**
 * The texture for the score text.
 */
extern SDL_Texture *scoreText;

/**
 * The texture for the lives text.
 */
extern SDL_Texture *livesText;

/**
 * The texture for the game over text.
 */
bool loadTextures(SDL_Renderer *renderer);

/**
 * Updates the score texture.
 *
 * @param state The current game state.
 * @param renderer The SDL renderer.
 * @return true if the texture was updated successfully, false otherwise.
 */
bool updateScoreTexture(GameState *state, SDL_Renderer *renderer);

/**
 * Updates the lives texture.
 *
 * @param state The current game state.
 * @param renderer The SDL renderer.
 * @return true if the texture was updated successfully, false otherwise.
 */
bool updateLivesTexture(GameState *state, SDL_Renderer *renderer);

/**
 * Frees all textures.
 *
 * @return true if the textures were freed successfully, false otherwise.
 */
bool freeTextures();

#endif
