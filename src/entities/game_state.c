#include "game_state.h"

static char **get_maps_array(void)
{
    char **map_files = malloc(sizeof(char*) * (MAPS + 1));
    map_files[0] = "tests/maps/level0.map";
    map_files[1] = "tests/maps/level1.map";
    map_files[2] = NULL;
    return map_files;
}

struct game_state *game_state_create(void)
{
    struct game_state *game_state = malloc(sizeof(struct game_state));
    if (!game_state)
        return NULL;
    game_state->player = NULL;
    game_state->list = list_create();
    game_state->map = NULL;
    init_mywindow(game_state);
    init_window(game_state);
    game_state->map_files = get_maps_array();
    game_state->game_won = false;
    return game_state;
}

void game_state_destroy(struct game_state *game_state)
{
    if (!game_state)
        return;
    player_destroy(game_state->player);
    list_destroy(game_state->list);
    free(game_state->map_files);
    close_sdl(game_state);
    free(game_state);
}
