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

enum direction
{
    LEFT = -1,
    RIGHT = 1,
    UP,
    DOWN,
    IDLE
};

struct entity
{
    struct pos pos;
    struct pos hitbox;
    enum entity_type type;
    enum direction dir;
};

struct player
{
    struct entity *entity;
    int score;
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

#endif /* ENTITY_H */
