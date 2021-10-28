#include "sort.h"

/**
 * swap_left: swap two nodes right left position
 * @list: list
 *Return: NULL
 *
 **/
void swap_left(listint_t *list)
{
	listint_t *tmp, *head;

	while (list->previous != NULL)
	{
		if (list->n < list->previous->n)
		{
			tmp = list->previous->previous;
			list->previous->next = list->next;
			list->next = list->previous;
			list->previous->previous = list;
			list->previous = tmp;
			list->next->next->previous = list->next;
			if (tmp != NULL)
				tmp->next = list;
			head = list;
			while (head->previous != NULL)
				head = head->previous;
			print_list(head);
		}
		else
			list = list->previous;
	}
}

/**
 * swap_right -swap two nodes left rigth position
 * @l: list
 * Return: Null
 **/
void swap_right(listint_t *l)
{
	listint_t *tmp, *head;

	tmp = l->previous;

	if (tmp != NULL)
	{
		tmp->next = l->next;
		l->next->previous = tmp;
	}
	else
		l->next->previous = NULL;
	l->previous = l->next;
	if (l->next->next != NULL)
	{
		l->next = l->next->next;
		l->previous->next = l;
		l->next->previous = l;
	}
	else
	{
		l->next->next = l;
		l->next = NULL;
	}
	head = l;
	while (head->previous != NULL)
		head = head->previous;
	print_list(head);
	swap_left(l->previous);
}

/**
 * insertion_sort_list -sorts a doubly linked list in ascending order
 * @list: list
 * Return: NULL
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *l;

	if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
		return;
	l = *list;

	while (l->next != NULL)
	{
		if (l->n > l->next->n)
		{
			swap_right(l);
		}
		else
			l = l->next;
	}
	while ((*list)->previous != NULL)
		*list = (*list)->previous;
}
