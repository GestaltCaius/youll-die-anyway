// init at going down
// then goes from up to down to up to down...
#include <stdio.h>
#include "move.h"

static struct pos get_entity_pos(struct entity *entity)
{
    struct pos pos;
    pos.x = floor(entity->pos.x);
    pos.y = floor(entity->pos.y);
    return pos;
}

/**
 * check if a < x < b
 * @return  1 if true, 0 if false
 */
static int is_between(float x, float a, float b)
{
    return a < x && x < b;
}

static int is_touching_wall(struct map *map, struct entity *entity)
{
    float epsilon = 0.2;
        struct pos pos = get_entity_pos(entity);
        int posx = pos.x;
        int posy = entity->dir == UP ? pos.y - 1 : pos.y + 2;
        return map->block_type[posy][posx] == ROCK
                && ((entity->dir == UP && is_between(entity->pos.y, pos.y,
                    pos.y + epsilon))
                || (entity->dir == DOWN && is_between(entity->pos.y,
                    pos.y + 1 - epsilon, pos.y + 1)));
}

void move_entity(struct game_state *gs)
{
    for (struct entity_list *list = gs->list; list; list = list->next)
    {
        struct entity *entity = list->data;
        if (!(entity->type == STONE))
            continue;
        if (!is_touching_wall(gs->map, entity))
            entity->pos.y = entity->dir == UP
                            ? entity->pos.y - 0.1 : entity->pos.y + 0.1;
        else
        {
            entity->dir = entity->dir == UP ? DOWN : UP;
        }
    }
}
