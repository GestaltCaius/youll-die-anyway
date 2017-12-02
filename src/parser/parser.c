#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

enum block_type get_block_type(char type, struct pos pos, 
                                    struct entity_list *list)
{
    if(type == 'R')
        return ROCK;
    else if(type == '.')
        return AIR;
    else if(type == 'K')
        list_add(list, pos, SPIKE);
    else if(type == 'S')
        list_add(list, pos, STONE);
    else if(type == 'G')
        list_add(list, pos, GROOMF);
    else if(type == 'P')
        player_create(pos)
    else if(type == 'E')
        return END;
}

struct map *parser(char *map_name, struct entity_list *list)
{
    FILE *f = fopen(map_name, "r");
    char *buffer = NULL;
    size_t line_length = 0;
    struct map *map = malloc(sizeof(struct map));
    ssize_t lineread = getline(&buffer, &line_length, f);
    if(lineread == -1)
        return NULL;
    map->width = atoi(strtok(buffer, " "));
    map->height = atoi(strtok(NULL, " "));
    map->block_type = malloc(sizeof(enum block_type) * map->height);
    for(int i = 0; (lineread = getline(&buffer, &line_length, f)) != -1; i++)
    {
        enum block_type line_block_type[map->width];
        for(int j = 0; buffer[j] != '\n'; j++)
        {
            struct pos pos = {j, i};
            line_block_type[j] = get_block_type(buffer[j], pos, list);
        }
        map->block_type[i] = line_block_type;
    }
    return map;
}

int main(void)
{
    struct map *map = parser("level0.map");
    printf("width: %d\n", map->width);
    printf("height: %d\n", map->height);
    free(map->block_type);
    free(map);
    return 0;
}
