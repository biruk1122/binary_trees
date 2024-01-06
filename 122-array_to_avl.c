#include "binary_trees.h"
#include <stddef.h>

/**
 * avl_insert - Inserts a value into an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value);

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    size_t i;

    if (array == NULL || size == 0)
        return NULL;

    for (i = 0; i < size; i++)
    {
        avl_insert(&root, array[i]);
    }

    return root;
}
