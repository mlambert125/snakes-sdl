#include <SDL2/SDL.h>

#ifndef INIT_H
#define INIT_H

/**
 * Initializes SDL and creates a window and renderer.
 *
 * @param window A pointer to the SDL_Window pointer to be initialized.
 * @param screenRenderer A pointer to the SDL_Renderer pointer to be initialized.
 * @return true if initialization was successful, false otherwise.
 */
bool initSdl(SDL_Window **window, SDL_Renderer **screenRenderer);

/**
 * Closes SDL and destroys the window and renderer.
 *
 * @param window A pointer to the SDL_Window pointer to be destroyed.
 * @param screenRenderer A pointer to the SDL_Renderer pointer to be destroyed.
 */
void sdlClose(SDL_Window **window, SDL_Renderer **screenRenderer);

#endif
