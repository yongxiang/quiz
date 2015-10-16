#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree)) {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->value = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->value) {
        insert(&(*tree)->left, val);
    } else if(val > (*tree)->value) {
        insert(&(*tree)->right, val);
    }
}
void print_preorder(Node * tree)
{
    if (tree) {
        printf("%d\n",tree->value);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}
void print_inorder(Node * tree)
{
    if (tree) {
        print_inorder(tree->left);
        printf("%d\n",tree->value);
        print_inorder(tree->right);
    }
}
void print_postorder(Node * tree)
{
    if (tree) {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->value);
    }
}

#endif
