#ifndef LOAD_MAP_H
#define LOAD_MAP_H
/**
 ** @file load_map.h
 ** @brief map file loader, creating/updating game_state structure
 ** @author Rod Guillaume
 ** @version 1.0
 ** @date 2017-12-03
 */

#include "game_state.h"
#include "parser.h"

/**
 ** @brief load the first map and creates game_state structure
 */
struct game_state *load_map_get_state(void);

/**
 ** @brief load the next map in game_state
 */
void *load_next_map(struct game_state *game_state);

#endif /* LOAD_MAP_H */
