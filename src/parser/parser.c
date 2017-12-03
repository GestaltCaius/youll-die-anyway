#include "parser.h"

enum block_type get_block_type(char type, struct pos pos,
                               struct game_state *game_state)
{
    if (type == 'R')
        return ROCK;
    else if (type == 'K')
        list_add(game_state->list, pos, SPIKE);
    else if (type == 'S')
        list_add(game_state->list, pos, STONE);
    else if (type == 'G')
        list_add(game_state->list, pos, GROOMF);
    else if (type == 'P')
        player_create(pos);
    else if (type == 'E')
    {
        game_state->end_pos.x = pos.x;
        game_state->end_pos.y = pos.y;
    }
    return AIR;
}

void print_map(struct game_state *gs)
{
    for(int i = 0; i < gs->map->height; i++)
    {
        for(int j = 0; j < gs->map->width; j++)
        {
            if(gs->map->block_type[i][j] == AIR)
                printf("A");
            else
                printf("R");
        }
        printf("\n");
    }
}

int parser(char *map_name, struct game_state *game_state)
{
    FILE *f = fopen(map_name, "r");
    char *buffer = NULL;
    size_t line_length = 0;
    struct map *map = malloc(sizeof(struct map));
    ssize_t lineread = getline(&buffer, &line_length, f);
    if(lineread == -1)
        return -1;
    map->width = atoi(strtok(buffer, " "));
    map->height = atoi(strtok(NULL, " "));
    map->block_type = malloc(sizeof(enum block_type*) * map->height);
    for(int i = 0; (lineread = getline(&buffer, &line_length, f)) != -1; i++)
    {
        map->block_type[i] = malloc(sizeof(enum block_type) * map->width);
        for(int j = 0; buffer[j] != '\n'; j++)
        {
            struct pos pos = {j, i};
            map->block_type[i][j] = get_block_type(buffer[j], pos,
                                                game_state);
        }
    }
    game_state->map = map;
    print_map(game_state);
    return 1;
}
