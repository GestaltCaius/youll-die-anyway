#include "sdl.h"

static SDL_Rect SDL_RectCreate(int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    return rect;
}

void window_render_map(struct game_state *gs)
{

    // TODO && chain those instructions to only have one return error.
    // they all return an int so it can be used as a boolean conds chaining

    // set background texture
    SDL_SetRenderDrawColor(gs->win->renderer, 0xFF, 0xFF,0xFF,0xFF);
    SDL_RenderClear(gs->win->renderer);

    for (size_t x = 0; x < SCREEN_WIDTH / BLOCK_SIZE; x++)
    {
        for (size_t y = 0; y < SCREEN_HEIGHT / BLOCK_SIZE; y++)
        {
            SDL_Rect block;
            switch(gs->map->block_type[y][x])
            {
                case AIR:
                    SDL_SetRenderTarget(gs->win->renderer,
                            gs->win->textures->background);
                    block = SDL_RectCreate(x * BLOCK_SIZE,
                            y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                    SDL_RenderCopy(gs->win->renderer,
                            gs->win->textures->background,NULL,&block);
                    break;
                case ROCK:
                    SDL_SetRenderTarget(gs->win->renderer,
                            gs->win->textures->rock);
                    block = SDL_RectCreate(x * BLOCK_SIZE,
                            y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                    SDL_RenderCopy(gs->win->renderer,
                            gs->win->textures->rock,NULL,&block);
                    break;
                case END:
                    SDL_SetRenderTarget(gs->win->renderer,
                            gs->win->textures->background);
                    block = SDL_RectCreate(x * BLOCK_SIZE,
                            y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                    SDL_RenderCopy(gs->win->renderer,
                            gs->win->textures->background,NULL,&block);
                    SDL_SetRenderTarget(gs->win->renderer,
                            gs->win->textures->end);
                    block = SDL_RectCreate(x * BLOCK_SIZE,
                            y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                    SDL_RenderCopy(gs->win->renderer,
                            gs->win->textures->end,NULL,&block);
                    break;
                default:
                    break;
            }
        }
    }
}

void render_live(struct game_state *gs)
{
    int count = gs->player->score;
    SDL_Rect block;
    for (size_t x = 0; count > 0 && x < SCREEN_WIDTH / BLOCK_SIZE; x++)
    {
        for (size_t y = 0; count > 0 && y < SCREEN_HEIGHT / BLOCK_SIZE; y++)
        {
            if(x == 0 && y < 4)
                continue;
            SDL_SetRenderTarget(gs->win->renderer,
                    gs->win->textures->life);
            block = SDL_RectCreate(y * BLOCK_SIZE,
                    x * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

            SDL_RenderCopy(gs->win->renderer,
                    gs->win->textures->life,NULL,&block);           
            count--;
        }
    }


}

void window_render_entity(struct game_state *gs)
{
    struct entity_list * tmp = gs->list;
    while(tmp)
    {
        SDL_Rect block;
        switch(tmp->data->type)
        {
            case SPIKE:
                SDL_SetRenderTarget(gs->win->renderer,
                        gs->win->textures->spike);
                block = SDL_RectCreate(tmp->data->pos.x * BLOCK_SIZE,
                        tmp->data->pos.y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                SDL_RenderCopy(gs->win->renderer,
                        gs->win->textures->spike,NULL,&block);
                break;
            case STONE:
                SDL_SetRenderTarget(gs->win->renderer,
                        gs->win->textures->stone);
                block = SDL_RectCreate(tmp->data->pos.x * BLOCK_SIZE,
                        tmp->data->pos.y* BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                SDL_RenderCopy(gs->win->renderer,
                        gs->win->textures->stone,NULL,&block);
                break;
            case GROOMF:
                SDL_SetRenderTarget(gs->win->renderer,
                        gs->win->textures->groomf);
                block = SDL_RectCreate(tmp->data->pos.x * BLOCK_SIZE,
                        tmp->data->pos.y* BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                SDL_RenderCopy(gs->win->renderer,
                        gs->win->textures->groomf,NULL,&block);
                break;
            case PLAYER:
                SDL_SetRenderTarget(gs->win->renderer,
                        gs->win->textures->hero);
                block = SDL_RectCreate(tmp->data->pos.x * BLOCK_SIZE,
                        tmp->data->pos.y* BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);

                SDL_RenderCopy(gs->win->renderer,
                        gs->win->textures->hero,NULL,&block);
                break;
            default:
                break;
        }
        tmp = tmp->next;
    }
}

void window_render_player(struct game_state *gs)
{
    SDL_Rect hblock;
    SDL_SetRenderTarget(gs->win->renderer,
            gs->win->textures->hero);
    hblock = SDL_RectCreate(gs->player->entity->pos.x * BLOCK_SIZE,
            gs->player->entity->pos.y * BLOCK_SIZE,BLOCK_SIZE, BLOCK_SIZE);
    SDL_RenderCopy(gs->win->renderer,
            gs->win->textures->hero,NULL,&hblock);
    SDL_RenderPresent(gs->win-> renderer);
}


void text_display(struct game_state *gs,char * text, int posx, int posy, 
        int w, int h,SDL_Color color)
{
    SDL_Surface * text1 = TTF_RenderText_Solid(gs->win->font,text,color);
    SDL_Texture *texturetext = SDL_CreateTextureFromSurface(gs->win->renderer,
            text1);
    SDL_Rect dstrect = { posx, posy, w, h };
    SDL_RenderCopy(gs->win->renderer,texturetext,NULL,&dstrect);
    SDL_DestroyTexture(texturetext);
    SDL_FreeSurface(text1);   
}

static SDL_Texture *text_quit;
static SDL_Texture *text_live;
static SDL_Texture *text_timer;
static SDL_Rect rect_quit;

void text_display_game(struct game_state *gs)
{
    if(!text_quit)
    {
        SDL_Color color = { 255, 0, 0, 0 };
        SDL_Surface * text1 = TTF_RenderText_Solid(gs->win->font,"Press Q to Quit"
                ,color);
        text_quit = SDL_CreateTextureFromSurface(gs->win->renderer,text1);
    }
    rect_quit.x =  0;
    rect_quit.y = 950 ;
    rect_quit.w = 250;
    rect_quit.h = 50;
    SDL_RenderCopy(gs->win->renderer,text_quit,NULL,&rect_quit);
    if(!text_live)
    {
        SDL_Color color = { 0, 255, 0 , 0 };
        SDL_Surface * text2 = TTF_RenderText_Solid(gs->win->font,"Death",color);
        text_live = SDL_CreateTextureFromSurface(gs->win->renderer,text2);
        rect_quit.x +=  300;
    }
    rect_quit.x =  10;
    rect_quit.y = 10 ;
    rect_quit.w = 100;
    rect_quit.h = 25;
    SDL_RenderCopy(gs->win->renderer,text_live,NULL,&rect_quit);
    if(!text_timer)
    {
        SDL_Color color = { 255, 0, 0, 0 };
        SDL_Surface * text3 = TTF_RenderText_Solid(gs->win->font,"Time: 0"
                ,color);
        text_timer = SDL_CreateTextureFromSurface(gs->win->renderer,text3);
        rect_quit.x +=  300;
    }
    rect_quit.x =  600;
    rect_quit.y = 950 ;
    rect_quit.w = 250;
    rect_quit.h = 50;
    SDL_RenderCopy(gs->win->renderer,text_timer,NULL,&rect_quit);
    //  SDL_DestroyTexture(texturetext);
    //  SDL_FreeSurface(text1);   
}
// Render struct map and characters
void game_window_draw(struct game_state *gs)
{

    //    SDL_Color color = { 255, 0, 0, 0 };
    window_render_map(gs);
    //    text_display(gs,"Press Q to Quit",0,SCREEN_HEIGHT * 5 / 6 ,250,50,color);
    //    text_display(gs,"live : 0 ", 300,SCREEN_HEIGHT * 5 / 6 ,250,50,color);
    //    text_display(gs,"timer : 0 ", 600,SCREEN_HEIGHT * 5 / 6 ,250,50,color);
    text_display_game(gs);
    render_live(gs);
    window_render_entity(gs);
    window_render_player(gs);

    SDL_RenderPresent(gs->win-> renderer);
}



void menu_window(struct game_state *gs)
{
    SDL_SetRenderDrawColor(gs->win->renderer, 0, 0,0,0);
    SDL_RenderClear(gs->win->renderer);

    SDL_Color color = { 255, 255, 255, 0 };
    text_display(gs,"You'll die anyway",62,100,900,200,color);

    text_display(gs,"Press Space to Play ", 312 ,350 ,400,100,color);   

    color.b = 0;
    color.g = 0;
    color.r= 255;
    text_display(gs,"Press Q to Quit",0,SCREEN_HEIGHT * 5 / 6 ,250,50,color);

    color.b = 255;
    color.g= 255;
    text_display(gs,"Zboubinours",SCREEN_WIDTH * 2/ 4,SCREEN_HEIGHT * 5 / 6,11 *
            40,50,color);
    text_display(gs,"Gobrunk",SCREEN_WIDTH * 2 / 4,SCREEN_HEIGHT * 5 / 6 + 50,7
            * 40,50,color);
    text_display(gs,"Nipica",SCREEN_WIDTH * 2 / 4,SCREEN_HEIGHT * 5 / 6 + 100 ,6
            * 40,50,color);

    SDL_RenderPresent(gs->win-> renderer);  


    if(Mix_PlayingMusic() == 0)
    {
        Mix_PlayMusic(gs->win->music_bg,  -1);
    }

    SDL_Event m;
    bool game = false;
    while(!game)
    {
        SDL_Delay(25);
        SDL_PollEvent(&m);
        if(m.type == SDL_KEYDOWN && m.key.keysym.sym == SDLK_SPACE)
            game = true;
        else if(m.type == SDL_KEYDOWN && m.key.keysym.sym == SDLK_q)
        {   
            gs->quit = true;
            break;
        }
    }


}




