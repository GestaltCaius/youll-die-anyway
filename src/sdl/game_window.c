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
                default:
                    break;
            }
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


// Render struct map and characters
void game_window_draw(struct game_state *gs)
{
    window_render_map(gs);
    window_render_entity(gs);
    window_render_player(gs);
    SDL_RenderPresent(gs->win-> renderer);
}

void text_display(struct game_state *gs,char * text, int posx, int posy, 
                    int w, int h,SDL_Color color)
{
    SDL_Surface * text1 = TTF_RenderText_Solid(gs->win->font,text,color);
    SDL_Texture *texturetext = SDL_CreateTextureFromSurface(gs->win->renderer,
        text1);
    int texW = 0; 
    int texH = 0;
    SDL_QueryTexture(texturetext, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { posx, posy, w, h };
    SDL_RenderCopy(gs->win->renderer,texturetext,NULL,&dstrect);
    SDL_DestroyTexture(texturetext);
    SDL_FreeSurface(text1);   
}


void menu_window(struct game_state *gs)
{
    SDL_SetRenderDrawColor(gs->win->renderer, 0xFF, 0xFF,0xFF,0xFF);
    SDL_RenderClear(gs->win->renderer);
    window_render_map(gs);

    SDL_Color color = { 0, 255, 0, 0 };
    text_display(gs,"IDK the Name",SCREEN_WIDTH / 4,0,600,100,color);
    text_display(gs,"By",2 * SCREEN_WIDTH / 4,100,100,100,color);
    text_display(gs,"Zboubinours",SCREEN_WIDTH / 4,250,400,50,color);
    text_display(gs,"Gobrunk",SCREEN_WIDTH / 4, 300,200,50,color);
    text_display(gs,"Nipica",SCREEN_WIDTH / 4,350,200,50,color);

    color.g = 0;
    color.r= 255;
    text_display(gs,"To Quit -- q -- ",0,SCREEN_HEIGHT * 5 / 6 ,250,50,color);
    
    text_display(gs,"To Play -- SPACE -- ", 300 ,SCREEN_HEIGHT * 5 / 6 ,
                    250,50,color);

    SDL_RenderPresent(gs->win-> renderer);  

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





















