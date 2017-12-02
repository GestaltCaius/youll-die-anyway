#include "game_main.h"

struct game_state *load_map_get_state(char *filename)
{
    // init game state
    struct game_state *game_state = game_state_create();
    if (!game_state)
        return NULL;
    // parse .map file
    if (parser(filename, game_state) < 0)
    {
        game_state_destroy(game_state);
        return NULL;
    }
    return game_state;
}
