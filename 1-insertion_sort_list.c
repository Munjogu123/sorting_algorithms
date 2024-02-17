#include "sort.h"

/**
 * insertion_sort_list - implements insertion sort
 * @list: pointer to the head node
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL)
		return;

	current = *list;
	while (current)
	{
		while (current->next && (current->n > current->next->n))
		{
			temp = current->next;
			current->next = temp->next;
			temp->prev = current->prev;

			if (temp->prev)
				temp->prev->next = temp;

			if (current->next)
				current->next->prev = current;

			current->prev = temp;
			temp->next = current;

			if (temp->prev)
				current = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
