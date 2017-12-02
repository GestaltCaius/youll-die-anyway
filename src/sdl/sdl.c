#include"sdl.h"

int main(int argc, char* argv[])
{
    argc = argc;
    argv = argv;
    init_mywindow();
    init_window();
    bool quit = false;
    SDL_Event e;
    modif_window();
    while(!quit)
    {
        SDL_PollEvent(&e);
        if(e.type == SDL_KEYDOWN)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_a:
                    quit = true;
                    break;
                case SDLK_b:
                    load_bg();
                    break;
                default:
                    modif_window();
            }
        }
    }

    close_sdl();
    return 0;
}
