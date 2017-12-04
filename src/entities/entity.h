#ifndef ENTITY_H
#define ENTITY_H

/**
** @file entity.h
** @brief Game entity structures
** @author Rod Guillaume
** @version 1.0
** @date 2017-12-02
*/

#include <stdlib.h>
#include "util.h"

enum entity_type
{
    SPIKE,
    STONE,
    GROOMF,
    PLAYER
};

/**
** @brief Entity movement for game_move function
*/
enum direction
{
    LEFT = -1,
    RIGHT = 1,
    UP,
    DOWN,
    IDLE
};

/**
**  @brief Hitbox object structure
*/
struct hitbox
{
    float x;
    float y;
    float size_x;
    float size_y;
};

/**
** @brief Game object structure
*/
struct entity
{
    struct pos pos;
    struct hitbox hitbox;
    enum entity_type type;
    enum direction dir;
};

/**
** @brief player related information and its entity field
*/
struct player
{
    struct entity *entity;
    struct pos start;
    float jump;
};

/**
** @brief Entity constructor
** @return new entity or NULL on error
*/
struct entity *entity_create(struct pos pos, enum entity_type type);

/**
** @brief Entity destructor
 **
** @param entity to destroy
*/
void entity_destroy(struct entity *entity);

/**
** @brief Player constructor
** @return new player or NULL on error
*/
struct player *player_create(struct pos pos);

/**
** @brief Player destructor
*/
void player_destroy(struct player *player);

#endif /* ENTITY_H*/
