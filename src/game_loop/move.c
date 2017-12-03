#include "move.h"

void gravity(struct game_state *game_state,
    struct entity *entity, float posx, float posy)
{
    struct map *map = game_state->map;
    struct player *player = game_state->player;
    int floor_x = floor(posx);
    int floor_y = floor(posy);
    if(floor_y != posy
        || (floor_x == posx && map->block_type[floor_y + 1][floor_x] != ROCK)
        || (floor_x != posx
            && map->block_type[floor_y + 1][floor_x] != ROCK
            && map->block_type[floor_y + 1][floor_x + 1] != ROCK))
    {
        if(player->jump == 0)
            entity->pos.y += GRAVITY;
    }
}

void jump(struct game_state *game_state,
    struct entity *entity, float posx, float posy)
{
    struct map *map = game_state->map;
    struct player *player = game_state->player;
    int floor_x = floor(posx);
    int floor_y = floor(posy);
    if(player->jump != 0)
    {
        if(map->block_type[floor_y][floor_x] != ROCK
            && (floor_x == posx
            || map->block_type[floor_y][floor_x + 1] != ROCK))
        {
            player->jump -= GRAVITY;
            entity->pos.y -= GRAVITY;
        }
    }
}

void h_move(struct game_state *game_state,
    struct entity *entity, float posx, float posy)
{
    struct map *map = game_state->map;
    int floor_x = floor(posx);
    int floor_y = floor(posy);
    if(posx > 0 && posx < map->width
        && map->block_type[floor_y][floor_x] != ROCK)
    {
        if(floor_x == posx && floor_y == posy)
            entity->pos.x = posx;
        else if(floor_x == posx && floor_y != posy
            && map->block_type[floor_y + 1][floor_x] != ROCK)
            entity->pos.x = posx;
        else if(floor_x != posx && floor_y == posy
            && map->block_type[floor_y][floor_x + 1] != ROCK)
            entity->pos.x = posx;
        else if(floor_x != posx && floor_y != posy
            && map->block_type[floor_y + 1][floor_x + 1] != ROCK)
            entity->pos.x = posx;
    }
}

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
    gravity(game_state, player, player->pos.x, player->pos.y);
    jump(game_state, player, player->pos.x, player->pos.y);
    h_move(game_state, player, player->pos.x + SPEED * xspeed, player->pos.y);
}

int check_hitbox(struct entity *player, struct entity *entity)
{
    if(player->pos.x >= entity->pos.x
        && player->pos.x <= entity->pos.x + entity->hitbox.x
        && player->pos.y >= entity->pos.y
        && player->pos.y <= entity->pos.y + entity->hitbox.y)
        return 0;
    if(player->pos.x + 1 >= entity->pos.x
        && player->pos.x + 1 <= entity->pos.x + entity->hitbox.x
        && player->pos.y >= entity->pos.y
        && player->pos.y <= entity->pos.y + entity->hitbox.y)
        return 0;
   if(player->pos.x >= entity->pos.x
        && player->pos.x <= entity->pos.x + entity->hitbox.x
        && player->pos.y + 1 >= entity->pos.y
        && player->pos.y + 1<= entity->pos.y + entity->hitbox.y)
        return 0;
   if(player->pos.x + 1 >= entity->pos.x
        && player->pos.x + 1 <= entity->pos.x + entity->hitbox.x
        && player->pos.y + 1 >= entity->pos.y
        && player->pos.y + 1 <= entity->pos.y + entity->hitbox.y)
        return 0;
    return 1;
}

void player_die(struct game_state *gs)
{
    struct player *player = gs->player;
    for(struct entity_list *list = gs->list; list; list = list->next)
    {
        struct entity *entity = list->data;
        if(check_hitbox(player->entity, entity) == 0)
        {
            player->entity->pos.x = player->start.x;
            player->entity->pos.y = player->start.y;
            player->score++;
            Mix_PlayChannel(-1,gs->win->stone_fall,0);
        }
    }
}

int player_end(struct game_state *gs)
{
    struct entity *player = gs->player->entity;
    if(player->pos.x >= gs->end_pos.x
        && player->pos.x <= gs->end_pos.x + 1
        && player->pos.y >= gs->end_pos.y
        && player->pos.y <= gs->end_pos.y + 1)
        return 0;
    if(player->pos.x + 1 >= gs->end_pos.x
        && player->pos.x + 1 <= gs->end_pos.x + 1
        && player->pos.y >= gs->end_pos.y
        && player->pos.y <= gs->end_pos.y + 1)
        return 0;
    if(player->pos.x >= gs->end_pos.x
        && player->pos.x <= gs->end_pos.x + 1
        && player->pos.y + 1 >= gs->end_pos.y
        && player->pos.y + 1 <= gs->end_pos.y + 1)
        return 0;
    if(player->pos.x + 1 >= gs->end_pos.x
        && player->pos.x + 1 <= gs->end_pos.x + 1
        && player->pos.y + 1 >= gs->end_pos.y
        && player->pos.y + 1 <= gs->end_pos.y + 1)
        return 0;
    return 1;

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
    move_entity(game_state);
    player_die(game_state);
    if(player_end(game_state) == 0)
        load_next_map(game_state);
}
