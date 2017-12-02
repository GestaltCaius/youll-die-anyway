#ifndef GAME_ENV_H
#define GAME_ENV_H

/**
 ** @file game_env.h
 ** @brief Game environment structures
 ** @author Rod Guillaume
 ** @version 1.0
 ** @date 2017-12-02
 */


#include <stdlib.h>

enum entity_type
{
    TRAP,
    ENEMY,
    PLAYER
};

enum direction
{
    LEFT,
    RIGHT,
    IDLE
};

struct pos
{
    float x;
    float y;
};

struct entity
{
    struct pos pos;
    enum entity_type type;
};

struct player
{
    struct entity *entity;
    int is_alive;
    int jump;
    enum direction dir;
};

struct game_state
{
    struct player player;
    struct entity_list *list;
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

#endif /* GAME_ENV_H */
