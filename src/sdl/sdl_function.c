#include "sdl.h"

bool init_window()
{
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Error SDL init! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
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
    SDL_Surface *screenSurface = SDL_GetWindowSurface( window );
    SDL_FillRect( screenSurface, NULL, 
            SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
    SDL_UpdateWindowSurface( window );
    SDL_Delay( 2000 );
}


