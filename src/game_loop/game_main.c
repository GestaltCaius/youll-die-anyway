#include "game_main.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
        return -1;
    struct game_state *game_state = load_map_get_state(argv[1]);
    if (!game_state)
        return -1;
    bool quit = false;
    while(!quit)
    {
        game_events(game_state);
        // MOVE FUNCTION GOES HERE
        game_window_draw(game_state);
    }
    game_state_destroy(game_state);
    return 0;
}
