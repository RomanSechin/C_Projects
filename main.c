//03_24 Ќаписать функцию, котора€ возвращает число узлов циклического списка, если задан
// указатель  одного из узлов списка
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node * next;
};

typedef struct node * link;

link create_llist(int n)
{
    if(n == 0) return NULL;

    int v = 0;
    link start = (link)malloc(sizeof(struct node));
    if(start == NULL) {printf("Can't allocate memory for start link!\n"); exit(1);}

    link temp = start;
    while(n--)
    {
        temp->value = v++;
        temp->next = (link)malloc(sizeof(struct node));
        temp = temp->next;
    }
    temp->next = start;
    return start;
};

void print_llist(link x)
{
    link start = x;
    while(x->next != start)
    {
        printf("%d\n", x->value);
        x = x->next;
    }
}

int count_of_items(link x)
{
    link temp = x;
    int count = 0;
    while(temp->next != x)
    {
        temp = temp->next;
        ++count;
    }
    return count;
}

int main()
{
    link list = create_llist(10);
    print_llist(list);
    printf("Count of items = %d\n", count_of_items(list->next->next));
    return 0;
}
