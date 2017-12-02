#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef SDL_H
#define SDL_H

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480

struct mywindow
{
    SDL_Window * window;
    SDL_Surface * window_surface;
    SDL_Surface * bg_surface;
    SDL_Renderer * renderer;
    SDL_Texture * texture;
};

struct mywindow *w;
void init_mywindow(void);
void close_sdl(void);
SDL_Texture* loadTexture(char* path);
bool init_window();
void modif_window();
bool load_bg(void);


#endif
