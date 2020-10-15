#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - function that stores recursively each level in an array of strings
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth
 * @sum: Buffe
 * Return: length after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **sum)
{
	char b[6];
	int width, left, right, is_left, a;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, sum);
	right = print_t(tree->right, offset + left + width, depth + 1, sum);
	for (a = 0; a < width; a++)
		sum[depth][offset + left + a] = b[a];
	if (depth && is_left)
	{
		for (a = 0; a < width + right; a++)
			sum[depth - 1][offset + left + width / 2 + a] = '-';
		sum[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (a = 0; a < left + width; a++)
			sum[depth - 1][offset - width / 2 + a] = '-';
		sum[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - functions that mesures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Function that prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **sum;
	size_t height, a, b;

	if (!tree)
		return;
	height = _height(tree);
	sum = malloc(sizeof(*sum) * (height + 1));
	if (!sum)
		return;
	for (a = 0; a < height + 1; a++)
	{
		sum[a] = malloc(sizeof(**sum) * 255);
		if (!sum[a])
			return;
		memset(sum[a], 32, 255);
	}
	print_t(tree, 0, 0, sum);
	for (a = 0; a < height + 1; a++)
	{
		for (b = 254; b > 1; --b)
		{
			if (sum[a][b] != ' ')
				break;
			sum[a][b] = '\0';
		}
		printf("%sum\n", sum[a]);
		free(sum[a]);
	}
	free(sum);
}
