#include "entity.h"

struct pos hitbox_create(enum entity_type type)
{
    struct pos pos;
    if(type == GROOMF)
    {
        pos.x = 0.25;
        pos.y = 0.25;
    }
    if(type == SPIKE)
    {
        pos.x = 1;
        pos.y = 1;
    }
    if(type == STONE)
    {
        pos.x = 1;
        pos.y = 1;
    }
    if(type == PLAYER)
    {
        pos.x = 1;
        pos.y = 1;
    }
    return pos;
}

struct entity *entity_create(struct pos pos, enum entity_type type)
{
    struct entity *entity = malloc(sizeof(struct entity));
    if (!entity)
        return NULL;
    entity->pos = pos;
    entity->type = type;
    entity->hitbox = hitbox_create(type);
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
    player->jump = 0;
    player->start = pos;
    player->score = 0;
    player->entity->dir = IDLE;
    return player;
}

void player_destroy(struct player *player)
{
    entity_destroy(player->entity);
    free(player);
}
