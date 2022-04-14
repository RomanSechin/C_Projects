//03_24 Написать функцию, которая возвращает число узлов циклического списка, если задан
// указатель  одного из узлов списка
//03_25 int nodes_between(x, t)
//определяет количество узлов, находящимися между узлами, на которые указывают x и t
//03_26 Написать функцию, которая по указателям x и t двух непересекаемых связных списков
// вставляет список, указываемый t, в список, указываемый x в позицию, которая следует
// после узла x
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
    if(start == NULL)
    {
        printf("Can't allocate memory for start link!\n");
        exit(1);
    }
    start->next = NULL;
    link temp = start;
    while(n--)
    {
        temp->value = v++;
        temp->next = (link)malloc(sizeof(struct node));
        temp = temp->next;
        temp->next = NULL;
    }
    temp->next = start;
    return start;
};

void print_llist(link x, char * msg)
{
    puts(msg);
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

int nodes_between(link x, link t)
{
    int count = 0;
    if(x == t) return count;
    while(x->next != t)
    {
        ++count;
        x = x->next;
    }
    return count;
}

void put_after_node(link x, link t)
{
    link temp = x->next;
    link start_t = t;
    link start_x = x;
    x->next = t;
    while(t->next != start_t)
    {
        t = t->next;
    }
    t->next = temp;
    while(t->next != start_t)
    {
        t = t->next;
    }
    //t->next = start_x;
}

int main()
{
    link list = create_llist(10);
    print_llist(list, "list:");
    link list2 = create_llist(20);
    print_llist(list2, "list2:");

    printf("Count of items = %d\n", count_of_items(list->next->next));
    printf("Count of nodes between x and t: %d\n", nodes_between(list, list->next->next->next));

    put_after_node(list, list2);
    print_llist(list, "list:");
    printf("Count of items = %d\n", count_of_items(list));
    return 0;
}
