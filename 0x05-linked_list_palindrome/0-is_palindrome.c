#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: head of the singly linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 **/
int is_palindrome(listint_t **head)
{
	listint_t  *left = *head;
	listint_t *right = *head;
	int len = 0, num;

	left = *head;
	num = recursive(left, right, len);
	if (num || *head == NULL)
		return (1);
	return (0);
}

/**
 * recursive - checks if a singly linked list is a palindrome
 * @left: head of the singly linked list
 * @right: tail of the singly linked list
 * @len: value of the singly linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 **/
int recursive(listint_t *left, listint_t *right, int len)
{
	int count = 0, num = len;

	if (right != NULL)
	{
		len++;
		num = recursive(left, right->next, len);
		if (num / 2 < len)
			return (num);
		if (num == 0)
			return (0);
	}
	else
		return (num);


	while (count < num - len)
	{
		left = left->next;
		count++;
	}

	if (left->n == right->n)
	{
		return (num);
	}
	else
		return (0);
}
