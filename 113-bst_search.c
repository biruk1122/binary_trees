#include "binary_trees.h"
#include <stddef.h>

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 *
 * Return: A pointer to the node containing a value equals to `value`,
 *         or NULL if tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL)
        return NULL;

    while (tree != NULL)
    {
        if (value == tree->n)
            return (bst_t *)tree;

        if (value < tree->n)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return NULL;
}
