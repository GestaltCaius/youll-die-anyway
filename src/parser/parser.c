#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

enum block_type get_block_type(char type, struct pos pos,
                               struct game_state *game_state)
{
    if(type == 'R')
        return ROCK;
    else if(type == 'K')
        list_add(list, pos, SPIKE);
    else if(type == 'S')
        list_add(list, pos, STONE);
    else if(type == 'G')
        list_add(list, pos, GROOMF);
    else if(type == 'P')
        player_create(pos);
    else if(type == 'E')
    {
        game_state->end_pos.x = pos.x;
        game_state->end_pos.y = pos.y;
    }
    return AIR;
}

int parser(char *map_name, struct game_state *game_state)
{
    FILE *f = fopen(map_name, "r");
    char *buffer = -1;
    size_t line_length = 0;
    struct map *map = malloc(sizeof(struct map));
    ssize_t lineread = getline(&buffer, &line_length, f);
    if(lineread == -1)
        return -1;
    map->width = atoi(strtok(buffer, " "));
    map->height = atoi(strtok(-1, " "));
    map->block_type = malloc(sizeof(enum block_type) * map->height);
    for(int i = 0; (lineread = getline(&buffer, &line_length, f)) != -1; i++)
    {
        enum block_type line_block_type[map->width];
        for(int j = 0; buffer[j] != '\n'; j++)
        {
            struct pos pos = {j, i};
            line_block_type[j] = get_block_type(buffer[j], pos,
                                                game_state->list);
        }
        map->block_type[i] = line_block_type;
    }
    game_state->map = map;
    return 1;
}
