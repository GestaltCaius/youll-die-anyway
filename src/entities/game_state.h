#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "entity.h"
#include "list.h"

struct game_state
{
    struct player *player;
    struct entity_list *list;
    struct map *map;
};

struct game_state *game_state_create(void);

void game_state_destroy(struct game_state *game_state);

#endif /* GAME_STATE_H */
