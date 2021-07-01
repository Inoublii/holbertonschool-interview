#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: address of the list that starting node
 * @str: the data of the new node
 * Return: Address of the new node, or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *node;

	if (!list || !str)
		return (NULL);
	node = malloc(sizeof(List));
	if (!node)
		return (NULL);
	node->str = strdup((const char *)str);
	if (!(node->str))
	{
		free(node);
		return (NULL);
	}
	if (!*list)
	{
		*list = node;
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->prev = (*list)->prev;
		node->next = *list;
		node->prev->next = node;
		node->next->prev = node;
	}
	return (node);
}

/**
 * add_node_begin - Add node to the beginning of a double circular linked list.
 * @list: the list to modify
 * @str: the string to copy into the new node.
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *newNode = NULL;
	char *nodeStr;

	if (!list || *list == NULL)
	{
		newNode = (List *) malloc(sizeof(List));
		if (!newNode)
			return (NULL);
		nodeStr = strdup(str);
		if (!nodeStr)
			return (NULL);
		newNode->str = nodeStr;
		newNode->prev = newNode;
		newNode->next = newNode;
		*list = newNode;
		return (newNode);
	}

	newNode = (List *) malloc(sizeof(List));
	if (!newNode)
		return (NULL);
	nodeStr = strdup(str);
	if (!nodeStr)
		return (NULL);
	newNode->str = nodeStr;
	newNode->next = (*list);
	if ((*list)->prev == NULL && (*list)->next == NULL)
	{
		(*list)->prev = newNode;
		(*list)->next = newNode;
		newNode->prev = (*list);
	}
	else
	{
		newNode->prev = (*list)->prev;
		(*list)->prev->next = newNode;
		(*list)->prev = newNode;
	}
	*list = newNode;
	return (newNode);
}
