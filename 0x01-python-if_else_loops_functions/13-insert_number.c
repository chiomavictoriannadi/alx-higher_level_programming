#include "lists.h"

/**
 * insert_node - This function nserts a number into a singly-linked list which is sorted.
 * @head: A pointer the head of the linked list.
 * @number: The number to insert.
 *
 * Return: if a function fails - NULL is returned.
 * Otherwise - a pointer to the new node is returned.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head, *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	if (node == NULL || node->n >= number)
	{
		new->next = node;
		*head = new;
		return (new);
	}

	while (node && node->next && node->next->n < number)
		node = node->next;

	new->next = node->next;
	node->next = new;

	return (new);
}
