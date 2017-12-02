#include"sdl.h"

int main(int argc, char* argv[])
{
    argc = argc;
    argv = argv;
    init_mywindow();
    init_window();
    bool quit = false;
    SDL_Event e;
    w->texture = loadTexture("../ressource/texture.png");
    while(!quit)
    {
        SDL_PollEvent(&e);
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a)
            quit = true;
        SDL_RenderClear(w->renderer);
        SDL_RenderCopy(w->renderer,w->texture,NULL,NULL);
        SDL_RenderPresent(w->renderer);
    }
    close_sdl();
    return 0;
}
