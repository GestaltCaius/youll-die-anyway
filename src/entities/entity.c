#include "entity.h"

struct hitbox hitbox_create(enum entity_type type)
{
    struct hitbox hitbox;
    if(type == GROOMF)
    {
        hitbox.x = 0.1875;
        hitbox.y = 0.4375;
        hitbox.size_x = 0.625;
        hitbox.size_y = 0.59375;
    }
    if(type == SPIKE)
    {
        hitbox.x = 0;
        hitbox.y = 0.875;
        hitbox.size_x = 1;
        hitbox.size_y = 0.125;

    }
    if(type == STONE)
    {
        hitbox.x = 0.0625;
        hitbox.y = 0.0625;
        hitbox.size_x = 0.875;
        hitbox.size_y = 0.875;

    }
    if(type == PLAYER)
    {
        hitbox.x = 0.15625;
        hitbox.y = 0.28125;
        hitbox.size_x = 0.6875;
        hitbox.size_y = 0.71875;

    }
    return hitbox;
}

struct entity *entity_create(struct pos pos, enum entity_type type)
{
    struct entity *entity = malloc(sizeof(struct entity));
    if (!entity)
        return NULL;
    entity->pos = pos;
    entity->type = type;
    switch (type)
    {
    case STONE:
        entity->dir = DOWN;
        break;
    case GROOMF:
        entity->dir = LEFT;
        break;
    default:
        entity->dir = IDLE;
        break;
    }
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
    player->entity->dir = IDLE;
    return player;
}

void player_destroy(struct player *player)
{
    entity_destroy(player->entity);
    free(player);
}
