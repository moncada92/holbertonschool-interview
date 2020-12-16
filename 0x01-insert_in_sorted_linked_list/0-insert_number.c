#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - insert in sorted node
 * @head: linked list
 * @number: value node
 * Return: linkedd list with new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode, *tmp;
	listint_t *current;

	current = *head;
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = number;
	if (current == NULL)
	{
		*head = newNode;
		(*head)->next = NULL;
		return (*head);
	}
	if (current->n > newNode->n)
	{
		newNode->next = current;
		*head = newNode;
		return (*head);
	}
	while (current != NULL)
	{
		if (current->next != NULL && current->next->n > newNode->n)
		{
			tmp = current->next;
			current->next = newNode;
			newNode->next = tmp;
			break;
		}
		else if (current->next == NULL && current->n < newNode->n)
		{
			current->next = newNode;
			newNode->next = NULL;
		}
		current = current->next;
	}
	return (current);
}
