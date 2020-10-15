#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: a pointer to the parent node
 * @value: value to put in the next node
 * Return: the address of the created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *next;

	next = malloc(sizeof(binary_tree_t));
	if (!next)
		return (NULL);
	next->parent = parent;
	next->n = value;
	next->left = NULL;
	next->right = NULL;
	return (next);
}
