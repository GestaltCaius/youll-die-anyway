#include "game_main.h"

game_events(struct game_state *game_state)
{
    SDL_Event e;
    SDL_PollEvent(&e);
    SDL_Delay(30);
    if(e.type == SDL_KEYDOWN)
    {
        switch(e.key.keysym.sym)
        {
        case SDLK_q:
            game_state->quit = true;
            break;
        case SDLK_r:
            game_state->restart = true;
            break;
        case SDLK_RIGHT:
            game_state->player->dir = RIGHT;
            break;
        case SDLK_LEFT:
            game_state->player->dir = LEFT;
            break;
        case SDLK_UP:
            game_state->player->dir = UP;
            break;
        default:
            continue;
        }
   }
}
