#ifndef SCENES_H
#define SCENES_H

#include <SDL2/SDL.h>
#include "../includes/state.h"

/**
 * The result of a scene function
 */
typedef struct Scene_Struct Scene;

/**
 * The result of a scene function
 */
struct Scene_Struct {
    /**
     * Whether the game should quit
     */
    bool quit;

    /**
     * A function pointer to the next scene
     */
    Scene (*scene_fn)(GameState *state, SDL_Renderer *renderer);
};

/**
 * The title scene
 *
 * @param state The game state
 * @param window The SDL window
 * @param renderer The SDL renderer
 * @param e The SDL event
 */
Scene sceneTitleScreen(GameState *state, SDL_Renderer *renderer);

/**
 * The main game scene
 *
 * @param state The game state
 * @param window The SDL window
 * @param renderer The SDL renderer
 * @param e The SDL event
 */
Scene sceneGame(GameState *state, SDL_Renderer *renderer);

/**
 * The game over scene
 *
 * @param state The game state
 * @param window The SDL window
 * @param renderer The SDL renderer
 * @param e The SDL event
 */
Scene sceneGameOver(GameState *state, SDL_Renderer *renderer);

#endif
