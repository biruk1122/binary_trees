#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest
        // in the right subtree)
        bst_t *temp = root->right;
        while (temp != NULL && temp->left != NULL)
            temp = temp->left;

        // Copy the in-order successor's content to this node
        root->n = temp->n;

        // Delete the in-order successor
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}
