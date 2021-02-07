#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - if the linked list is cycle
 * @list: linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *crnt1 = list, *crnt2 = list;

	if (list == NULL)
		return (0);

	if (crnt2->next == NULL)
		return (0);
	crnt2 = crnt2->next->next;

	while (crnt1 != NULL && crnt2 != NULL)
	{
		crnt1 = crnt1->next;

		if (crnt2->next == NULL)
			return (0);
		crnt2 = crnt2->next->next;

		if (crnt1 == crnt2)
			return (1);
	}

	return (0);
}
