#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_tree_height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return 0;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return ((left_height > right_height) ? left_height : right_height) + 1;
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height, balance_factor;

    if (tree == NULL)
        return 1;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    balance_factor = abs(left_height - right_height);

    if (balance_factor > 1)
        return 0;

    return binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right);
}
