#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef SDL_H
#define SDL_H


#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480

SDL_Window * window;
bool init_window();
void modif_window();


#endif
