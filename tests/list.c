#include "../src/list.h"
#include "../src/entity.h"
#include <stdio.h>

void print_list(struct entity_list *list)
{
    printf("[ ");
    for (; list; list = list->next)
    {
        char type = 'X';
        switch (list->data->type)
        {
        case STONE:
            type = 'S';
            break;
        case SPIKE:
            type = '!';
            break;
        case PLAYER:
            type = 'P';
            break;
        case GROOMF:
            type = 'G';
            break;
        }
        printf("type(%c) id(%d) pos(%f, %f), ",
               type, list->id,
               list->data->pos.x, list->data->pos.y);
    }
    printf(" ]\n");
}

int main(void)
{
    struct entity_list *list = list_create();
    struct pos pos = {1, 1 };
    list = list_add(list, pos, GROOMF);
    pos = (struct pos){2, 1 };
    list = list_add(list,pos, SPIKE);
    pos = (struct pos){3, 1 };
    list = list_add(list,pos, GROOMF);
    pos = (struct pos){4, 1 };
    list = list_add(list,pos, STONE);
    pos = (struct pos){5, 1 };
    list = list_add(list, pos, GROOMF);
    print_list(list);
    list_destroy(list);
}
