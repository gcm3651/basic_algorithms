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

int init_data(node_t **list, int size)
{
    int i = 0;
    for(; i< size; i++)
    {
        add_node(list, rand()%100);
    }
}

void reverse_print(node_t *node)
{
    if(node->next)
    {
        reverse_print(node->next);
    }

    printf("%d->", node->value);
}

int main(int argc, char *argv[])
{
    int size = atoi(argv[1]);
    node_t *list = NULL;
    init_data(&list, size);
    printf("normal print: ");
    print_list(list);
    
    printf("\nreverse print: ");
    reverse_print(list);
    printf("\n");
}
