
/*
*/
#define BLOCK_SIZE 16

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
void game_window_create(void)
{
    init_mywindow();
    init_window();
}

// Render struct map and characters
void game_window_draw(struct game_state *game_state)
{
    // TODO && chain those instructions to only have one return error.
    // they all return an int so it can be used as a boolean conds chaining

    // set background texture
    SDL_SetRenderTarget(SDL_Renderer* renderer, SDL_Texture*  texture);
    SDL_RenderClear(SDL_Renderer* renderer);
    for (size_t x = 0; x < w->w; x++)
    {
        for (size_t y = 0; y < w->h; y++)
        {
            SDL_Texture *texture = get_block_texture(game_state->map[x][y]);
            SDL_Rect block = SDL_RectCreate(x * BLOCK_SIZE, y * BLOCK_SIZE,
                                            BLOCK_SIZE, BLOCK_SIZE);
            SDL_RenderSetViewport(SDL_Renderer*   renderer,
                          const SDL_Rect* rect);
            SDL_RenderCopy(SDL_Renderer*   renderer,
                   SDL_Texture*    texture,
                   const SDL_Rect* srcrect,
                   const SDL_Rect* dstrect);
            SDL_RenderPresent(SDL_Renderer* renderer);
        }
    }
    close_sdl();
}
