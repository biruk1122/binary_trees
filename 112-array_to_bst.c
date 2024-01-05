#include "binary_trees.h"
#include <stddef.h>

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;

    bst_t *root = NULL;

    for (size_t i = 0; i < size; i++)
    {
        bst_insert(&root, array[i]);
    }

    return root;
}
