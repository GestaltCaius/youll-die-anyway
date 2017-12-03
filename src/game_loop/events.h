#ifndef events_H
#define events_H

/**
** @file events.h
** @brief Events listener for main game loop
** @author Rod Guillaume
** @version 1.0
** @date 2017-12-03
*/


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include "game_state.h"
#include "sdl.h"

/**
** @brief Checks if player has pressed a key
*/
void game_events(struct game_state *game_state);

#endif
