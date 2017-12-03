#include "move.h"


void player_move(struct game_state *game_state)
{
    struct entity *player = game_state->player->entity;
    int xspeed = 0;
    switch(player->dir)
    {
        case RIGHT:
            xspeed++;
            break;
        case LEFT:
            xspeed--;
            break;
        default:
            break;
    }
    float posx = player->pos.x + SPEED * xspeed;
    float posy = player->pos.y;
    int floor_posx = floor(posx);
    int floor_posy = ceil(posy);
    struct map *map = game_state->map;
    if(map->block_type[floor_posy + 1][floor_posx] != ROCK
        || posy != floor_posy)
    {
        player->pos.y = posy + GRAVITY;
        posy = player->pos.y;
        floor_posy = floor(posy);
    }
    if(posx > 0 && map->block_type[floor_posy][floor_posx - 1] != ROCK
        && posx + 1 < map->width
        && map->block_type[floor_posy][floor_posx + 1] != ROCK)
    {
        player->pos.x = posx;
    }
}

void game_move(struct game_state *game_state)
{
    for (struct entity_list *list = game_state->list; list; list = list->next)
    {
        switch(list->data->dir)
        {
        case LEFT:
            list->data->pos.x -= SPEED;
            break;
        case RIGHT:
            list->data->pos.x += SPEED;
            break;
        default:
            break;
        }
    }
    player_move(game_state);
}
