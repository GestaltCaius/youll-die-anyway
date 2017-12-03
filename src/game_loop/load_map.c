#include "load_map.h"

struct game_state *load_map_get_state(void)
{
    // init game state
    struct game_state *game_state = game_state_create();
    if (!game_state)
        return NULL;
    // parse .map file
    if (parser(game_state->map_files[0], game_state) < 0)
    {
        game_state_destroy(game_state);
        return NULL;
    }
    game_state->map->id = 0;
    return game_state;
}

void *load_next_map(struct game_state *game_state)
{
    int new_id = game_state->map->id + 1;
    if (game_state->map_files[new_id] == 0)
    {
        game_state->game_won = true;
        return game_state;
    }
    list_destroy(game_state->list);
    if (parser(game_state->map_files[new_id], game_state) < 0)
    {
        game_state_destroy(game_state);
        return NULL;
    }
    game_state->map->id = new_id;
    return game_state;
}
