#ifndef MOVE_H
#define MOVE_H

#define SPEED 0.2
#define GRAVITY 0.5

#include <math.h>
#include "game_state.h"
#include "load_map.h"

void game_move(struct game_state *game_state);
void move_entity(struct game_state *gs);

#endif /* MOVE_H */
