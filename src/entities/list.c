#include "list.h"

struct entity_list *list_create(void)
{
    struct entity_list *list = malloc(sizeof(struct entity_list));
    if (!list)
        return NULL;
    list->data = NULL;
    list->id = 0;
    list->next = NULL;
    return list;
}

static void list_destroy_node(struct entity_list *list)
{
    if (!list)
        return;
    entity_destroy(list->data);
    free(list);
}

void list_destroy(struct entity_list *list)
{
    struct entity_list *next;
    struct entity_list *curr = list;
    while (curr)
    {
        next = curr->next;
        list_destroy_node(curr);
        curr = next;
    }
}

static struct entity_list *list_create_node(struct entity *entity, int id)
{
    struct entity_list *new_node = malloc(sizeof(struct entity_list));
    if (!new_node)
        return NULL;
    new_node->data = entity;
    new_node->id = id;
    new_node->next = NULL;
    return new_node;
}

static int list_is_empty(struct entity_list *list)
{
    return list && !list->data && !list->id && !list->next;
}

struct entity_list *list_add(struct entity_list *list,
                             struct pos pos,
                             enum entity_type type)
{
    if (!list)
        return NULL;
    struct entity *new_entity = entity_create(pos, type);
    if (!new_entity)
        return NULL;
    struct entity_list *last = list;
    if (list_is_empty(list))
    {
        list->data = new_entity;
        return list;
    }
    while (last->next)
        last = last->next;
    struct entity_list *new_node = list_create_node(new_entity, last->id + 1);
    if (!new_node)
    {
        free(new_entity);
        return NULL;
    }
    last->next = new_node;
    return list;
}

void list_remove(struct entity_list *list, int id)
{
    struct entity_list *prev = NULL;
    for (; list && list->id != id; list = list->next)
        prev = list;
    if (list && prev)
    {
        prev->next = list->next;
        list_destroy_node(list);
    }
}
