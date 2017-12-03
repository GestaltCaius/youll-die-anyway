#include "move.h"

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
    struct entity *player = game_state->player->entity;
    switch(player->dir)
    {
    case LEFT:
        player->pos.x -= SPEED;
        break;
    case RIGHT:
        player->pos.x += SPEED;
        break;
    default:
        break;
    }
}
