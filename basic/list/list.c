#include <stdio.h>
#include <stdlib.h>
typedef struct node_s
{
    int value;
    struct node_s* next;
}node_t;

node_t *t = NULL;


void add_node(node_t **head, int value)
{
    node_t *cur = (node_t *)malloc(sizeof(node_t));
    cur->value = value;

    if(!*head)
    {
        *head = cur;
        return;
    }
    else
    {
        node_t *p = *head;
        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = cur;
        cur->next = NULL;
    }
}

void print_list(node_t *head)
{
    if(!head)
    {
        return;
    }
    
    node_t *p = head;
    while(p)
    {
        printf("%d->", p->value);
        p = p->next;
    }
    printf("NULL\n");
}


void main()
{
    node_t *list = NULL;
    add_node(&list, 1);
    add_node(&list, 3);
    add_node(&list, 2);
    add_node(&list, 6);
    add_node(&list, 4);
    
    print_list(list);
}
