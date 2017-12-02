#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef SDL_H
#define SDL_H

#define SCREEN_WIDTH  960
#define SCREEN_HEIGHT  320
#define BLOCK_SIZE 32

struct mywindow
{
    SDL_Window * window;
    SDL_Surface * window_surface;
    SDL_Surface * bg_surface;
    SDL_Renderer * renderer;
    struct textures textures;
};

struct textures
{
    SDL_Texture *background;
    SDL_Texture *stone;
    SDL_Texture *rock;
    SDL_Texture *hero;
    SDL_Texture *groomf;
    SDL_Texture *spike;
}

enum color
{
    BLACK,
    WHITE,
    RED
};

struct mywindow *w;
void init_mywindow(struct game_state *gs);
void close_sdl(struct game_state *gs);
SDL_Texture* loadTexture(char* path,struct game_state *gs);
bool init_window(struct game_state *gs);

#endif
