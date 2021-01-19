#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * is_palindrome - check if is palidrome a linked list
 * @head: linked list
 * Return: if is palindrome 1 otherwise 0
 */

int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	listint_t *tmp, *tmp2, *tmp3;
	int first = 0;
	int last = 0;
	int search_middle = 0;

	if (current == NULL)
		return (0);
	tmp3 = *head;
	while (current->next != NULL)
	{
		if (search_middle)
			first += 0;
		else
			first++;
		if (current->n == current->next->n)
		{
			search_middle = 1;
			tmp = current->next;
			tmp2 = current->next;
			while (tmp != NULL)
			{
				//printf("----- TMP -----\n");
				last++;
				//printf("%d \n", tmp->n);
				//printf("--------------- \n");
				tmp = tmp->next;
				if (tmp == NULL)
					break;
			}
		}
		current = current->next;
	}
	if (first == last)
	{
		int result = is_equal(&tmp3, &tmp2);
		if (result)
			return (1);
	} else {
		return (0);
	}

	return (0);
}

/**
 * is_equal - if it is igual
 * head
 */

int is_equal(listint_t **current, listint_t **tmp)
{
	listint_t *prev = NULL, *currnt = *tmp;
	listint_t *next;

	while (currnt != NULL) {
		next = currnt->next;
		currnt->next = prev;
		prev = currnt;
		currnt = next;
	}

	*tmp = prev;

	while (*tmp)
	{
		if ((*tmp)->n != (*current)->n)
		{
			printf("tmp: %d != current: %d \n", (*tmp)->n, (*current)->n);
			return (0);
		}

		*tmp = (*tmp)->next;
		*current = (*current)->next;
	}

	return (1);
}
