#include "sdl.h"


void init_mywindow(struct game_state * gs)
{
    gs->win = malloc(sizeof(struct mywindow));
    gs->win->window = NULL;
    gs->win->window_surface = NULL;
    gs->win->bg_surface = NULL;
    gs->win->renderer = NULL;
    gs->win->textures = malloc(sizeof(struct textures));
}

void close_sdl(struct game_state *gs)
{
    SDL_FreeSurface(gs->win->window_surface);
    SDL_FreeSurface(gs->win->bg_surface);

    SDL_DestroyTexture(gs->win->textures->background);
    SDL_DestroyTexture(gs->win->textures->stone);
    SDL_DestroyTexture(gs->win->textures->hero);
    SDL_DestroyTexture(gs->win->textures->groomf);
    SDL_DestroyTexture(gs->win->textures->spike);
    SDL_DestroyTexture(gs->win->textures->rock);
    
    TTF_CloseFont(gs->win->font);
    TTF_Quit();


    SDL_DestroyRenderer(gs->win->renderer);
    SDL_DestroyWindow(gs->win->window);
    SDL_Quit();
    free(gs->win->textures);
    free(gs->win);
}

bool init_window(struct game_state *gs)
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Error SDL init! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        gs->win->window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gs->win->window == NULL )
        {
            printf( "Error windows creation! SDL_Error: %s\n", SDL_GetError() );
            return false;
        }
        gs->win->renderer = SDL_CreateRenderer( gs->win->window, -1,
                SDL_RENDERER_ACCELERATED );
        if( gs->win->renderer == NULL )
        {
            printf( "Renderer not created!SDL Error: %s\n", SDL_GetError());
            return false;
        }
        SDL_SetRenderDrawColor( gs->win->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            printf( "SDL_image not initialize!SDL_image Error: %s\n",
                    IMG_GetError() );
            return false;
        }
    }
    
    TTF_Init();
    gs->win->font = TTF_OpenFont("src/ressource/beauty.ttf", 1000);
    if(!gs->win->font)
        printf("error loading font\n");
        
    // initialization texture
    gs->win->textures->background =
    loadTexture("src/ressource/png_texture/background.png",gs);
    gs->win->textures->stone =
    loadTexture("src/ressource/png_texture/stone.png",gs);
    gs->win->textures->hero =
    loadTexture("src/ressource/png_texture/hero.png",gs);
    gs->win->textures->rock =
    loadTexture("src/ressource/png_texture/rock.png",gs);
    gs->win->textures->groomf =
    loadTexture("src/ressource/png_texture/groomf.png",gs);
    gs->win->textures->spike =
    loadTexture("src/ressource/png_texture/spike.png",gs);
    return true;
}

SDL_Texture* loadTexture( char* path,struct game_state *gs )
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path,
            IMG_GetError() );
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface( gs->win->renderer, loadedSurface);
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path,
                SDL_GetError() );
        }
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}


/*
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
*/
