#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "tree.h"
static double diff(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec *1000000000.0+ diff.tv_nsec );
}

void flatten(Node *root)
{
    assert(root);
    Node *root_left, *root_right;
    root_left = root->left;
    root_right = root->right;

    if (root_left == NULL) return;
    if (root_right == NULL) {
        flatten(root_left);
        root->right=root_left;
        root->left=NULL;
        return;
    }

    flatten(root_left);
    flatten(root_right);
    Node *tmp = root_left;
    while (tmp->right != NULL)
        tmp = tmp->right;

    root->right=root_left;
    root->left=NULL;
    tmp->right = root_right;

    return;
}

int main()
{
    struct timespec start, end;
    Node *root = NULL;
    insert(&root, 1);
    insert(&(root->left), 2);
    insert(&(root->left->left), 3);
    insert(&(root->left), 4);
    insert(&root, 5);
    insert(&root, 6);

    print_preorder(root);
    printf("\n");
    print_inorder(root);
    printf("\n");
    print_postorder(root);
    printf("\n");
    clock_gettime(CLOCK_REALTIME, &start);
    flatten(root);
    clock_gettime(CLOCK_REALTIME, &end);
    print_preorder(root);
    printf("\n");
    print_inorder(root);
    printf("\n");
    print_postorder(root);
    printf("\n");

    printf(" execution time is %lf nsec \n", diff(start,end));
    return 0;
}
