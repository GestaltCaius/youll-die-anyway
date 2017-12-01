#include"sdl.h"

int main(int argc, char* argv[])
{
    argc = argc;
    argv = argv;
    static SDL_Window* window = NULL;
    init_window();
    modif_window();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
