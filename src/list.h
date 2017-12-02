#ifndef LIST_H
#define LIST_H

#include "game_env.h"

struct entity_list
{
    struct entity *data;
    int id;
    struct entity_list *next;
};

struct entity_list *list_add(struct entity_list *list,
                             struct pos pos,
                             enum entity_type type);

void list_destroy(struct entity_list *list);

struct entity_list *list_create(void);

void list_remove(struct entity_list *list, int id);

#endif /* LIST_H */
