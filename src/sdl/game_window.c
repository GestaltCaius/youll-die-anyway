#include "sdl.h"

static SDL_Rect SDL_RectCreate(int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    return rect;
}

// init_mywindow + init_window in global variable w
// TODO discuss about integrating w variable into game_state structure
/*void game_window_create(struct game_state *game_state)
  {
// TODO might merge those two bad boys
init_mywindow(game_state->win);
init_window(game_state->win);
}*/
/*
   static enum color get_block_texture(char block)
   {
   switch (block)
   {
   case '.':
   return WHITE;
   break;
   case 'S':
   return BLACK;
   break;
   default:
   return RED;
   break;
   }i*/

// Render struct map and characters
void game_window_draw(struct game_state *gs)
{
    // TODO && chain those instructions to only have one return error.
    // they all return an int so it can be used as a boolean conds chaining

    // set background texture
    SDL_SetRenderDrawColor(gs->win->renderer, 0xFF, 0xFF,0xFF,0xFF);
    SDL_RenderClear(gs->win->renderer);

    for (size_t x = 0; x < SCREEN_WIDTH / BLOCK_SIZE; x++)
    {
        for (size_t y = 0; y < SCREEN_HEIGHT / BLOCK_SIZE; y++)
        {
            SDL_SetRenderTarget(gs->win->renderer,
                    gs->win->textures->background);
            SDL_Rect block = SDL_RectCreate(x * BLOCK_SIZE, y * BLOCK_SIZE,
                    BLOCK_SIZE, BLOCK_SIZE);

            SDL_RenderSetViewport(gs->win->renderer, &block);
            SDL_RenderCopy(gs->win->renderer,
                    gs->win->textures->background,
                    NULL,
                    &block);
        }
    }
    SDL_RenderPresent(gs->win-> renderer);
}
