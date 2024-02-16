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

void inorder(struct N *node)
{
    opcount++;
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(struct N *node)
{
    opcount++;
    if (node != NULL)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct N *node)
{
    opcount++;
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
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

    printf("\nMade tree\nTraversing Pre-order - ");
    start = clock();
    preorder(root);
    end = clock();
    printf("\nTime taken - %f", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\nOPCount - %d", opcount);
    printf("\nTraversing In-order - ");
    opcount = 0;
    start = clock();
    inorder(root);
    end = clock();
    printf("\nTime taken - %f", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\nOPCount - %d", opcount);
    printf("\nTraversing Post-order - ");
    opcount = 0;
    start = clock();
    postorder(root);
    end = clock();
    printf("\nTime taken - %f", (double)(end - start) / CLOCKS_PER_SEC);  
    printf("\nOPCount - %d", opcount);  
}