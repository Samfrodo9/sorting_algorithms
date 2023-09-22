#include "sort.h"

/**
 * insertion_sort_list - An insertion sort list algorithm
 * @list: Address of a pointer to a list pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;
		prev_node = current->prev;

		while (prev_node != NULL && prev_node->n > current->n)
		{
			/* Swap current and prev_node */
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = prev_node;

			prev_node->next = current->next;
			current->prev = prev_node->prev;

			current->next = prev_node;
			prev_node->prev = current;

			prev_node = current->prev;
			print_list(*list);
		}

		current = next_node;
	}
}

/**
 * Algorithm - Here is the algorithm
 * Check if the input list is empty or has only one element.
 * If so, return because it's already sorted.
 * This is because the first element is considered sorted initially.
 * Initialize a current pointer to the second element in the list.
 * Enter a loop that iterates until current becomes null:
 * a. Inside the loop, initialize a next_node pointer
 * to current.next and a prev_node pointer to current.prev.
 * b. Enter another loop that iterates while prev_node is not null
 * and prev_node.n is greater than current.n:
 * i. Swap current and prev_node to correctly insert current
 * into the sorted part of the list.
 * ii. Update the next and prev pointers of the nodes involved in the swap.
 * iii. Move prev_node to the previous node for the next iteration.
 * c. After the inner loop completes, move current to the
 * next node (next_node) for the next iteration.
 * The outer loop continues until current becomes null,
 * and the list becomes sorted.
*/
