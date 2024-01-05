#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Calculate the height of the leftmost leaf node */
    int height = 0;
    const binary_tree_t *temp = tree;
    while (temp->left != NULL)
    {
        height++;
        temp = temp->left;
    }

    /* Check if all leaf nodes are at the same level */
    return is_perfect_recursive(tree, 0, height);
}

/**
 * is_perfect_recursive - Recursive helper function to check perfection
 * @tree: Pointer to the current node
 * @level: Current level in the tree
 * @height: Height of the leftmost leaf node
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, int level, int height)
{
    if (tree == NULL)
        return (level == height);
    if (tree->left == NULL && tree->right == NULL)
        return (level == height);

    if (tree->left == NULL || tree->right == NULL)
        return (0);
    return (is_perfect_recursive(tree->left, level + 1, height) &&
            is_perfect_recursive(tree->right, level + 1, height));
}
