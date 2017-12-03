#ifndef LIST_H
#define LIST_H

/**
** @file list.h
** @brief entity list implementation
** @author Rod Guillaume
** @version 1.0
** @date 2017-12-03
*/


#include <stdlib.h>
#include "entity.h"

/**
** @brief entity list element
*/
struct entity_list
{
    struct entity *data;
    int id;
    struct entity_list *next;
};

/**
** @brief Add an enemy to the entity list (creates it)
*/
struct entity_list *list_add(struct entity_list *list,
                             struct pos pos,
                             enum entity_type type);

/**
** @brief entity list destructor
*/
void list_destroy(struct entity_list *list);

/**
** @brief entity list constructor
*/
struct entity_list *list_create(void);

/**
** @brief remove entity from entity list using its id
*/
void list_remove(struct entity_list *list, int id);

#endif /* LIST_H*/
