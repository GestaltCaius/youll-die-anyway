#ifndef ENTITY_H
#define ENTITY_H

enum entity_type
{
    TRAP,
    ENEMY,
    PLAYER
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
    struct entity entity;
    bool is_alive;
    bool jump;
    enum direction dir;

};

struct game_state
{
    struct player player;
    struct entity_list *list entities;
};

struct entity *entity_create(struct pos pos, enum entity_type type);
struct entity *entity_destroy(struct pos pos, enum entity_type type);

#endif /* ENTITY_H */
