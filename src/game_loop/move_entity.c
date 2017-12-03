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
    return a <= x && x <= b;
}

static int is_touching_wall(struct map *map, struct entity *entity)
{
    float epsilon = 0.2;
    struct pos pos = get_entity_pos(entity);
    int posx;
    int posy;
    if (entity->dir == UP || entity->dir == DOWN)
    {
        posx = floor(pos.x);
        posy = floor(entity->dir == UP ? pos.y - 1 : pos.y + 1);
    }
    else
    {
        posx = floor(entity->dir == LEFT ? pos.x - 1 : pos.x + 1);
        posy = floor(pos.y);
    }
    return map->block_type[posy][posx] == ROCK
            && ((entity->dir == UP && is_between(entity->pos.y, pos.y,
                pos.y + epsilon))
            || (entity->dir == DOWN && is_between(entity->pos.y + 1,
                pos.y + 1 - epsilon, pos.y + 1 + epsilon))
            || (entity->dir == LEFT && is_between(entity->pos.x,
                pos.x, pos.x + epsilon))
            || (entity->dir == RIGHT && is_between(entity->pos.x + 1,
                pos.x + 1 - epsilon, pos.x + 1 + epsilon)));
}

void move_entity(struct game_state *gs)
{
    for (struct entity_list *list = gs->list; list; list = list->next)
    {
        struct entity *entity = list->data;
        if (entity->type == SPIKE)
            continue;
        if (!is_touching_wall(gs->map, entity))
        {
            switch (entity->dir)
            {
            case UP:
                entity->pos.y -= 0.1;
                break;
            case DOWN:
                entity->pos.y += 0.1;
                break;
            case LEFT:
                entity->pos.x -= 0.01;
                break;
            case RIGHT:
                entity->pos.x += 0.01;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (entity->dir)
            {
            case UP:
                entity->dir = DOWN;
                break;
            case DOWN:
                entity->dir = UP;
                break;
            case LEFT:
                entity->dir = RIGHT;
                break;
            case RIGHT:
                entity->dir = LEFT;
                break;
            default:
                break;
            }
        }
    }
}
