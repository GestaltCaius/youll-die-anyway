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

#endif /* ENTITY_H */
