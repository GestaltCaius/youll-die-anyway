#ifndef GAME_STATE_H
#define GAME_STATE_H

/**
** @file game_state.h
** @brief Game environment structure, containing all game loop info
** @author Rod Guillaume
** @version 1.0
** @date 2017-12-03
*/


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdlib.h>

#include "entity.h"
#include "list.h"

#define MAPS 10

/**
** @brief Game object textures
*/
struct textures
{
    SDL_Texture *background;
    SDL_Texture *stone;
    SDL_Texture *rock;
    SDL_Texture *hero;
    SDL_Texture *groomf;
    SDL_Texture *spike;
    SDL_Texture *end;
    SDL_Texture *life;
};

/**
** @brief SDL Window structure containing textures, SDL info and audio
*/
struct mywindow
{
    SDL_Window * window;
    SDL_Surface * window_surface;
    SDL_Surface * bg_surface;
    SDL_Renderer * renderer;
    struct textures *textures;
    TTF_Font * font;
    Mix_Music *music_bg;
    Mix_Music *music_bg2;
    Mix_Chunk *move;
    Mix_Chunk *jump;
    Mix_Chunk *die;
    Mix_Chunk *enemy;
    Mix_Chunk *stone_fall;
    Mix_Chunk *pike;


};

/**
** @brief Main game structure
*/
struct game_state
{
    struct player *player;
    int score;
    struct entity_list *list;
    struct pos end_pos;
    struct map *map;
    char **map_files;
    struct mywindow *win;
    bool game_won;
    bool quit;
    bool restart;
};


#include "sdl.h"

/**
** @brief game_state constructor
*/
struct game_state *game_state_create(void);

/**
** @brief game_state destructor
*/
void game_state_destroy(struct game_state *game_state);

#endif /* GAME_STATE_H*/
