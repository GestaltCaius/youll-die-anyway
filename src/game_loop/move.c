#define SPEED 10
#define GRAVITY 10

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
        case UP:
            list->data->pos.y -= SPEED;
            break;
        case DOWN:
            list->data->pos.y += SPEED;
            break;
        case IDLE:
            break;
        }
        list->data->pos.x += SPEED;
    }
}
