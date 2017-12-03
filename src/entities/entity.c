#include "entity.h"

struct entity *entity_create(struct pos pos, enum entity_type type)
{
    struct entity *entity = malloc(sizeof(struct entity));
    if (!entity)
        return NULL;
    entity->pos = pos;
    entity->type = type;
    entity->dir = type == STONE ? DOWN : IDLE;
    return entity;
}

void entity_destroy(struct entity *entity)
{
    free(entity);
}

struct player *player_create(struct pos pos)
{
    struct player *player = malloc(sizeof(struct player));
    if (!player)
        return NULL;
    player->entity = entity_create(pos, PLAYER);
    if (!player->entity)
    {
        free(player);
        return NULL;
    }
    player->is_alive = 1;
    player->jump = 0;
    player->entity->dir = IDLE;
    return player;
}

void player_destroy(struct player *player)
{
    entity_destroy(player->entity);
    free(player);
}
