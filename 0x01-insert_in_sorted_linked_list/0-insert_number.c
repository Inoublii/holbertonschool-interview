#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - inserts a node into a sorted singly linked list
 * @head: double pointer to head of linked list
 * @number: integer to insert into list
 * Return: address of current node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = malloc(sizeof(listint_t)), *a;

	if (!head || !current)
		return (NULL);

	current->next = NULL;
	current->n = number;

	if (!*head)
	{
		*head = current;
		return (current);
	}

	a = *head;
	if (a->n > number)
	{
		current->next = a;
		*head = current;
		return (current);
	}

	while (a->next != NULL && a->next->n < number)
		a = a->next;
	current->next = a->next;
	a->next = current;
	return (current);
}
