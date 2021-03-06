#include "binary_trees.h"

/**
 *init_new_node - init the node to add
 *@parent: new node pointer
 *@arr: ptr to the first element of the array
 *@idx: new node array index
 *Return: ptr to the new  head node or NULL on
 */
avl_t *init_new_node(avl_t *parent, int *arr, size_t idx)
{
	avl_t *new;

	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);

	new->n = arr[idx];
	new->parent = parent;
	new->right = NULL;
	new->left = NULL;

	return (new);
}

/**
 *avl_tree - Builds an AVL tree from an array
 *@parent: new node pointer
 *@arr: ptr to the first element
 *@beg: start index
 *@end: end
 *Return: ptr to the head node or NULL
 */
avl_t *avl_tree(avl_t *parent, int *arr, size_t beg, size_t end)
{
	avl_t *new;
	size_t idx = (beg + end) / 2;

	new = init_new_node(parent, arr, idx);
	if (!new)
		return (NULL);

	if (idx != end)
		new->right = avl_tree(new, arr, idx + 1, end);
	if (idx != beg)
		new->left = avl_tree(new, arr, beg, idx - 1);

	return (new);
}

/**
 *sorted_array_to_avl - Builds an AVL tree from an array
 *@array: ptr to the first element
 *@size: the array size
 *Return: ptr to the head node of AVL, or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (!array || size == 0)
		return (NULL);

	tree = avl_tree(NULL, array, 0, size - 1);

	return (tree);
}
