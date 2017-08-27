#include <stdio.h>
#include "node.h"
#include <stdlib.h>
int root_first_arr[]={1, 2, 4, 7, 3, 5, 6, 8};
int left_first_arr[]={4, 7, 2, 1, 5, 3, 8, 6};
node_t *tree = NULL;

#define q_size 100
node_t *queue[q_size]={0};
int q_s = 0;
int q_e = 0;

void inqueue(node_t *node)
{
    queue[q_e] = node;
    q_e++;
    if(q_e==q_size)
    {
        q_e=0;
    }
}

node_t* dequeue()
{
    int cur = q_s;
    q_s++;
    if(q_e==q_size)
    {
        q_s =0;
    }

    return queue[cur];
}

int is_queue_null()
{
    return q_s == q_e;
}

int find_idx(int *arr, int len, int value)
{
    int i=0;
    while(arr[i]!=value&&i<len)
    {
        i++;
    }

    if(i == len)
    {
        return -1;
    }

    return i;
}

void init_leaf_node(int flag, node_t *node)
{
    if(flag == -1)
    {
        node->lchild = NULL;
    }
    else
    {
        node->rchild = NULL;
    }
}

int rebuild(int flag, node_t **node, int *root_first, int len1, int s1, int e1, int *left_first, int len2, int s2, int e2)
{
    if(!*node)
    {
        *node = (node_t *)calloc(sizeof(node_t) ,1);
        (*node)->value = root_first[s1];
    }else
    {
        node_t *cur_node = (node_t *)calloc(sizeof(node_t),1);
        cur_node->value = root_first[s1];
        if(flag == -1)
        {
            (*node)->lchild = cur_node;
        }
        else
        {
            (*node)->rchild = cur_node;
        }

        node = &cur_node;
    }
    int root_value;
    if(s1 >= len1)
    {
        return -1;
    }

    root_value = root_first[s1];
    
    int root_idx = find_idx(left_first, len2, root_value);
    
    int left_size = root_idx - s2;
    //rebuild left
    if(root_idx==s2)
    {
        init_leaf_node(-1, *node);
        //return;
    }
    else
    {
        rebuild(-1, node, root_first, len1, s1+1, s1+1+(left_size-1), left_first, len2, s2, root_idx-1);
    }

    //rebuild right
    if(root_idx==e2)
    {
        init_leaf_node(1, *node);
    }
    else
    {
        rebuild(1, node, root_first, len1, s1+1+left_size, e1, left_first, len2, root_idx+1, e2);
    }
}

void print_node(node_t *node)
{
    if(node)
    {
        printf("%d  ", node->value);
        inqueue(node);
    }
    else
    {
        printf("NULL  ");
        inqueue(NULL);
    }
}

void print_tree(node_t *tree)
{
    if(!tree)
    {
        printf("tree is null\n");
        return;
    }

    printf("%d\n", tree->value);
    printf("%d  ", tree->lchild->value);
    printf("%d  ", tree->rchild->value);
    inqueue(tree->lchild);
    inqueue(tree->rchild);
    node_t *cur;
    while(!is_queue_null())
    {
        cur = dequeue();
        print_node(cur->lchild);
        print_node(cur->rchild);

        if(cur == 1)
        {
            printf("\n");
            inqueue(1);
        }
    }
}

int main()
{
    int arr1_size = sizeof(root_first_arr)/sizeof(int);
    int arr2_size = sizeof(left_first_arr)/sizeof(int);
    rebuild(0, &tree, root_first_arr, arr1_size, 0, arr1_size-1, left_first_arr, arr2_size, 0, arr2_size-1);
    print_tree(tree);
}
