#ifndef LOAD_MAP_H
#define LOAD_MAP_H

#include "game_state.h"
#include "parser.h"

/**
 * [load_map_get_state description]
 * @param  filename [description]
 * @return          NULL on error
 */
struct game_state *load_map_get_state(void);

/**
 * [load_next_map description]
 * @param  game_state [description]
 * @return            NULL on error
 */
void *load_next_map(struct game_state *game_state);
#endif /* LOAD_MAP_H */
