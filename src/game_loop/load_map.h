#ifndef LOAD_MAP_H
#define LOAD_MAP_H

#include "game_state.h"


// TODO talk with francois about parser IN/OUT
/*
 * Might be better to return an int as error code
 * and taking a game_state structure in argument to fill up player, map, list
 *
 * One prototype could be the following
 * int parser_map(char *filename, struct game_state *game_state);
 *
 * return -1 on error, 1 otherwise
 * game_state has player, map and entity_list fields
 */

struct game_state *load_map_get_state(char *filename);

#endif /* LOAD_MAP_H */
