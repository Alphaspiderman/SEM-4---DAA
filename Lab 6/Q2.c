#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcount = 0;

struct N
{
    int data;
    struct N *left, *right;
} *root;

struct N *create(struct N *bnode, int x)
{
    if (bnode == NULL)
    {
        bnode = (struct N *)malloc(sizeof(struct N));
        bnode->data = x;
        bnode->left = bnode->right = NULL;
    }
    else if (x > bnode->data)
        bnode->right = create(bnode->right, x);
    else if (x < bnode->data)
        bnode->left = create(bnode->left, x);
    else
    {
        printf("Duplicate node\n");
        exit(0);
    }
    return bnode;
}

int height(struct N *node)
{
    opcount++;
    if (node == NULL)
        return 0;
    else
    {
        int lh = height(node->left);
        int rh = height(node->right);

        return (lh > rh) ? lh + 1 : rh + 1;
    }
}

void inorder(struct N *node)
{
    
    if (node != NULL)
    {
        inorder(node->left);
        int b = height(node->left) - height(node->right);
        printf("\n%d - %d", node->data, b);
        inorder(node->right);
    }
}

void main()
{
    root = NULL;
    int n;
    printf("Enter number of nodes - ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        root = create(root, rand());
    }

    clock_t start, end;

    printf("\nMade tree\n");
    start = clock();
    inorder(root);
    end = clock();
    printf("\nTime taken - %f", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\nOPCount - %d", opcount);
}