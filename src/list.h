#ifndef LIST_H
#define LIST_H

#include "entity.h"

struct entity_list
{
    struct entity *data;
    struct entity_list *next;
    int id;
};

struct entity_list *list_add(struct entity_list *list,
                             struct pos pos,
                             enum entity_type type);

struct entity_list *list_create(void);

void list_destroy(struct entity_list *list);

#endif /* LIST_H */
