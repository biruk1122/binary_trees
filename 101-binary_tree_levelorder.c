#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Use a queue to perform level-order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
    int front = 0, rear = 0;

    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *current = queue[front++];

        /* Call the function for the current node */
        func(current->n);

        /* Enqueue left child if exists */
        if (current->left != NULL)
            queue[rear++] = current->left;

        /* Enqueue right child if exists */
        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    /* Free the queue */
    free(queue);
}
