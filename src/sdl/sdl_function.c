#include "sdl.h"


void init_mywindow(void)
{
    w = malloc(sizeof(struct mywindow));
    w->window = NULL;
    w->window_surface = NULL;
    w->bg_surface = NULL;

}

void close_sdl(void)
{
    SDL_FreeSurface(w->window_surface);
    SDL_FreeSurface(w->bg_surface);
    SDL_DestroyWindow(w->window);
    SDL_Quit();
    free(w);
}

bool init_window()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Error SDL init! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        w->window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( w->window == NULL )
        {
            printf( "Error windows creation! SDL_Error: %s\n", SDL_GetError() );
            return false;
        }
        else
            return true;
    }
}

void modif_window()
{
    w->window_surface= SDL_GetWindowSurface( w->window );
    SDL_FillRect( w->window_surface, NULL, 
            SDL_MapRGB( w->window_surface->format, 60, 60, 60 ) );
    SDL_UpdateWindowSurface( w->window );
}

bool load_bg(void)
{
    bool returnV = true;

    SDL_Surface * tmp  = IMG_Load("../ressource/background.png");
    if( tmp == NULL )
    {
        printf( "Unable to load bg image! SDL Error: %s\n", SDL_GetError() );
        returnV = false;
    }
    w->bg_surface = SDL_ConvertSurface(tmp,w->window_surface->format, 0);
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT;
    SDL_BlitSurface( w->bg_surface, NULL, w->window_surface, &stretchRect );
    SDL_UpdateWindowSurface(w->window);
    SDL_FreeSurface(tmp);
    return returnV;
}

