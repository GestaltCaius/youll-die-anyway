#include "game_main.h"

int main(void)
{
    struct game_state *game_state = load_map_get_state();
    if (!game_state)
        return -1;
    bool menu = true;
    while(!game_state->quit)
    {
        SDL_Delay(25);
        if(menu)
        {
            menu_window(game_state);
            menu = false;
        }
        game_events(game_state);
        game_move(game_state);
        game_window_draw(game_state);


    }
    game_state_destroy(game_state);
    return 0;
}
