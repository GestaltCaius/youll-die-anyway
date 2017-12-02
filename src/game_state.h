#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "entity.h"

struct game_state
{
    struct player player;
    struct entity_list *list;
};

struct game_state *game_state_create(void);

void game_state_create(struct game_state *game_state);

#endif /* GAME_STATE_H */
