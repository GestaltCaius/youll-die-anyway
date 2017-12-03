#ifndef PARSER_H
# define PARSER_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "entity.h"
#include "game_state.h"
#include "list.h"

enum block_type
{
    ROCK,
    AIR,
    END
};

struct map
{
    int width;
    int height;
    enum block_type **block_type;
};


/**
 ** @brief loads a map from a .map file
 **
 ** @param map_name .map file
 ** @param list enemies list
 **
 ** @return .map file translated into a map structure
 */
int parser(char *map_name, struct game_state *game_state);

#endif
