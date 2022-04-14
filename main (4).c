//03_47 Написать программу, которая удаляет все узлы связного списка
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node * next
};

typedef struct node * link;

link freelist;
link llist;

link initNodes(link list, int N)
{
    int i;
    list = (link)malloc((N+1)*sizeof( * list));
    for(i = 0; i < N + 1; ++i)
        list[i].next = &list[i+1];
    list[N].next = NULL;
    printf("Link created (%d nodes)\n", N);
    return list;
}

void deleteLink(link x)
{
    link t; int count = 0;
    while(x->next)
    {
        insertNext(freelist, x);
        ++count;
    }
    printf("Link deleted (%d nodes)\n", count);
}
link deleteNext(link x)
{
    link t = x->next;
    x->next = t->next;
    return t;
}

void insertNext(link t)
{
    link temp = freelist->next;
    t->next = temp;
    freelist->next = t;
}

int main()
{
    initNodes(llist, 10);
    initNodes(freelist, 0);
    deleteLink(llist);
    return 0;
}
