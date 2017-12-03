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

void window_render_map(struct game_state *gs)
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
            SDL_Rect block;
            switch(gs->map->block_type[y][x])
            {
                case AIR:
                    SDL_SetRenderTarget(gs->win->renderer,
                            gs->win->textures->background);
                    block = SDL_RectCreate(x * BLOCK_SIZE,
                            y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                    SDL_RenderCopy(gs->win->renderer,
                            gs->win->textures->background,NULL,&block);
                    break;
                case ROCK:
                    SDL_SetRenderTarget(gs->win->renderer,
                            gs->win->textures->rock);
                    block = SDL_RectCreate(x * BLOCK_SIZE,
                            y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                    SDL_RenderCopy(gs->win->renderer,
                            gs->win->textures->rock,NULL,&block);
                    break;
                default:
                    break;
            }
        }
    }
}

void window_render_entity(struct game_state *gs)
{
    struct entity_list * tmp = gs->list;
    while(tmp)
    {
        SDL_Rect block;
        switch(tmp->data->type)
        {
            case SPIKE:
                SDL_SetRenderTarget(gs->win->renderer,
                        gs->win->textures->spike);
                block = SDL_RectCreate(tmp->data->pos.x * BLOCK_SIZE,
                        tmp->data->pos.y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                SDL_RenderCopy(gs->win->renderer,
                        gs->win->textures->spike,NULL,&block);
                break;
            case STONE:
                SDL_SetRenderTarget(gs->win->renderer,
                        gs->win->textures->stone);
                block = SDL_RectCreate(tmp->data->pos.x * BLOCK_SIZE,
                        tmp->data->pos.y* BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                SDL_RenderCopy(gs->win->renderer,
                        gs->win->textures->stone,NULL,&block);
                break;
            case GROOMF:
                SDL_SetRenderTarget(gs->win->renderer,
                        gs->win->textures->groomf);
                block = SDL_RectCreate(tmp->data->pos.x * BLOCK_SIZE,
                        tmp->data->pos.y* BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                SDL_RenderCopy(gs->win->renderer,
                        gs->win->textures->groomf,NULL,&block);
                break;
            case PLAYER:
                SDL_SetRenderTarget(gs->win->renderer,
                        gs->win->textures->hero);
                block = SDL_RectCreate(tmp->data->pos.x * BLOCK_SIZE,
                        tmp->data->pos.y* BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                SDL_RenderCopy(gs->win->renderer,
                        gs->win->textures->hero,NULL,&block);
                break;
            default:
                break;
        }
        tmp = tmp->next;
    }
}

void window_render_player(struct game_state *gs)
{
    SDL_Rect hblock;
    SDL_SetRenderTarget(gs->win->renderer,
            gs->win->textures->hero);
    hblock = SDL_RectCreate(gs->player->entity->pos.x * BLOCK_SIZE,
            gs->player->entity->pos.y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);
    SDL_RenderCopy(gs->win->renderer,
            gs->win->textures->hero,NULL,&hblock);
    SDL_RenderPresent(gs->win-> renderer);
}


// Render struct map and characters
void game_window_draw(struct game_state *gs)
{
    window_render_map(gs);
    window_render_entity(gs);
    window_render_player(gs);
    SDL_RenderPresent(gs->win-> renderer);
}


