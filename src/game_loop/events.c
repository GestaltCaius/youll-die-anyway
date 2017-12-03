#include "events.h"

static int is_on_ground(struct game_state *gs)
{
    int posy = gs->player->entity->pos.y;
    int posx = gs->player->entity->pos.x;
    return gs->map->block_type[posy + 1][posx] == ROCK;
}

void game_events(struct game_state *game_state)
{
    SDL_Event e;
    SDL_PollEvent(&e);
    struct player *player = game_state->player;
    if(e.type == SDL_KEYDOWN)
    {
        switch(e.key.keysym.sym)
        {
        case SDLK_UP:
            if (player->jump == 0 && is_on_ground(game_state))
                player->jump = 2.0;
            break;
        case SDLK_q:
            game_state->quit = true;
            break;
        case SDLK_r:
            game_state->restart = true;
            break;
        case SDLK_RIGHT:
            game_state->player->entity->dir = RIGHT;
            break;
        case SDLK_LEFT:
            game_state->player->entity->dir = LEFT;
            break;
        default:
            break;
        }
   }
}
