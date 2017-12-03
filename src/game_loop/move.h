#ifndef MOVE_H
#define MOVE_H
/**
** @file move.h
** @brief move function for main game loop
** @author Rod Guillaume, Francois Kremer
** @version 1.0
** @date 2017-12-03
*/

#define SPEED 0.2
#define GRAVITY 0.5

#include <math.h>

#include "game_state.h"
#include "load_map.h"

/**
** @brief main move function, updates all entities and player positions
*/
void game_move(struct game_state *game_state);

/**
** @brief sub function of move, for entities only
*/
void move_entity(struct game_state *gs);

#endif /* MOVE_H*/
