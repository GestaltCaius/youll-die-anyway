#include"sdl.h"

int main(int argc, char* argv[])
{
    argc = argc;
    argv = argv;
    init_mywindow();
    init_window();
    bool quit = false;
    SDL_Event e;
    int height_rect = SCREEN_HEIGHT / 4;
    //    w->texture = loadTexture("../ressource/texture.png");
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
                case SDLK_DOWN:
                    height_rect--;
                    break;
                case SDLK_UP:
                    height_rect++;
                    break;
                default:
                    continue;

            }
        }
        SDL_SetRenderDrawColor( w->renderer, 0xFF, 0xFF, 0xFF, 0xF);
        SDL_RenderClear( w->renderer );

        SDL_Rect fillRect = { SCREEN_WIDTH / 4, height_rect,
            SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_SetRenderDrawColor( w->renderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect( w->renderer, &fillRect );

        SDL_RenderPresent(w->renderer);

        /*SDL_RenderClear(w->renderer);
          SDL_RenderCopy(w->renderer,w->texture,NULL,NULL);
          SDL_RenderPresent(w->renderer);*/
    }
    close_sdl();
    return 0;
}
