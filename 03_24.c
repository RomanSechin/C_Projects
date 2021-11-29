//Ќапишите функцию, котора€ возвращает число узлов циклического списка, если задан указатель одного из узлов списка
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    struct node * start = create(0);
    struct node * iterator = start;
    for(int i = 1; i < 10; ++i)
    {
        struct node * next_node = (struct node * )malloc(sizeof(struct node));
        if(next_node)
        {
            next_node->item = i;
            insertAfter(iterator, next_node);
            iterator->next = next_node;
        }

    }
    displayNodes(start);
    removeList(start);
    displayNodes(start);
    return 0;
}
