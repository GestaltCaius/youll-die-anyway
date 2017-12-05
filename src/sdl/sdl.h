#ifndef SDL_H
#define SDL_H

/**
** @file sdl.h
** @brief SDL Window functions
** @author Nicolas Ribeyrolle
** @version 1.0
** @date 2017-12-03
*/


#define SCREEN_WIDTH  1024 
#define SCREEN_HEIGHT  1024
#define BLOCK_SIZE 32

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
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


/**
** @brief SDL Window constructor
*/
void init_mywindow(struct game_state *gs);

/**
** @brief SDL Window destructor
*/
void close_sdl(struct game_state *gs);

/**
** @brief PNG file texture loader
** @return 
*/
SDL_Texture* loadTexture(char* path,struct game_state *gs);

/**
** @brief Draw function for main game loop
*/
void game_window_draw(struct game_state *gs);

/**
** @brief SDL Window initializer
*/
bool init_window(struct game_state *gs);

/**
** @brief Main title window draw function
*/
void menu_window(struct game_state *gs);

/**
** @brief End title draw function
*/
void menu_end(struct game_state *gs);

#endif
