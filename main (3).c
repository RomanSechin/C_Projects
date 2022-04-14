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
    for(int i = 0; i < n-1; ++i)
    {
        temp->value = i;
        temp->next = (link)malloc(sizeof(struct node));
        temp = temp->next;
        temp->next = NULL;
    }
    temp->value = n-1;
    temp->next = start;
    return start;
};

void print_llist(link x, char * msg)
{
    puts(msg);
    link start = x;
    while(1)
    {
        printf("%d\n", x->value);
        x = x->next;
        if(x->next == start)
            return;
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
    //link start_x = x;
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

void next_to_next(link x, link t)
{
    link what = t->next;
    link temp = x->next;
    x->next = what;
    what->next = temp;
}

link reverse(link x)
{
    link r = NULL, y = x, t;
    int r_val;
    int y_val = y->value;
    int t_val;
    int y_next_val;// = y->next->value;

    while(y->next != x)
    {
        t = y->next;    t_val = t->value;
        y->next = r;
        y_next_val = t->value;

        r = y;  r_val = r->value;
        y = t;  y_val = y->value;
    }
    return r;
}

int main()
{
    link list = create_llist(10);
    print_llist(list, "list:");
    //link list2 = create_llist(20);
    //print_llist(list2, "list2:");
    //03_24
    //printf("Count of items = %d\n", count_of_items(list->next->next));
    //03_25
    //printf("Count of nodes between x and t: %d\n", nodes_between(list, list->next->next->next));
    //03_26
    //put_after_node(list, list2);
    //print_llist(list, "list:");
    //printf("Count of items = %d\n", count_of_items(list));

    //03_27
    //next_to_next(list->next->next, list2->next->next);
    //print_llist(list, "after next_to_next(list->next->next, list2->next->next)");

    //reverse list
    //printf("%d\n", list->value);
    print_llist(reverse(list), "Reverse list:");
//    link x = list;
//    for(int i = 0; i < 12; ++i)
//    {
//        printf("%d: %u- %d\n", i, x, x->value);
//        x = x->next;
//    }
    return 0;
}
