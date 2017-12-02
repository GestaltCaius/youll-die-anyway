
#ifndef events_H
#define events_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>

#include "game_state.h"
#include "sdl.h"

void game_events(struct game_state *game_state);

#endif
