#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - if the linked list is cycle
 * @list: linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *start = list;
	listint_t *end = list;

	if (list != NULL || list->next != NULL)
	{
		return (0);
	}


	if (list == list->next)
	{
		return (1);
	}

	while (end->next != NULL && end->next->next != NULL)
	{
		start = start->next;
		end = end->next->next;

		if (start == end)
			return (1);
	}

	return (0);
}
