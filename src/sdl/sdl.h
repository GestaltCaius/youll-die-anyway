#ifndef SDL_H
#define SDL_H

#define SCREEN_WIDTH  1024
#define SCREEN_HEIGHT  1024
#define BLOCK_SIZE 32

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "game_state.h"
#include "parser.h"

enum color
{
    BLACK,
    WHITE,
    RED
};


void init_mywindow(struct game_state *gs);
void close_sdl(struct game_state *gs);
SDL_Texture* loadTexture(char* path,struct game_state *gs);
void game_window_draw(struct game_state *gs);
bool init_window(struct game_state *gs);
void menu_window(struct game_state *gs);
void menu_end(struct game_state *gs);
#endif
