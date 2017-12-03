#ifndef PARSER_H
# define PARSER_H

/**
** @file parser.h
** @brief .map parser, creating map structure and entity_list
** @author Francois Kremer
** @version 1.0
** @date 2017-12-03
*/


#include <stdio.h>
#include <stdlib.h>
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

/**
 ** @brief map structure, translation of the .map file
 */
struct map
{
    int width;
    int height;
    int id;
    enum block_type **block_type;
};


/**
** @brief loads a map from a .map file
** @param map_name .map file
** @param list enemies list
** @return .map file translated into a map structure
*/
int parser(char *map_name, struct game_state *game_state);

/**
** @brief map structure destructor
*/
void map_destroy(struct map *map);

#endif
