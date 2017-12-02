#include "game_state.h"

struct game_state *game_state_create(void)
{
    struct game_state *game_state = malloc(sizeof(struct game_state));
    if (!game_state)
        return NULL;
    game_state->player = NULL;
    game_state->list = list_create();
    init_mywindow(game_state);
    init_window(game_state);
    return game_state;
}

void game_state_destroy(struct game_state *game_state)
{
    if (!game_state)
        return;
    player_destroy(game_state->player);
    list_destroy(game_state->list);
    close_adl(game_state);
    free(game_state);
}
