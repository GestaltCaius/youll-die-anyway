#include "game_main.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
        return -1;
    // LOAD MAP
    struct game_state *game_state = load_map_get_state(argv[1]);
    if (!game_state)
        return -1;
    // INIT SDL WINDOW
    bool quit = false;
    SDL_Event e;
    while(!quit)
    {
        // EVENTS
        // MOVE FUNCTION GOES HERE
        game_window_draw(game_state);
    }


    game_state_destroy(game_state);
    return 0;
}
