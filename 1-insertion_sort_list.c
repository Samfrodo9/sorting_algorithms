#include "sort.h"

/**
 * insertion_sort_list - An insertion sort list algorithm
 * @list: Address of a pointer to a list pointer
*/

void insertion_sort_list(listint_t **list)
{
	/**
	 * ypedef struct listint_s

    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
	*/

	if ((!list) || !(*list))
	{
		return;
	}

	if ((*list)->next == NULL)
		return;

	listint_t *transverse = (*list); /*Sorted List*/
	listint_t *next_transverse = transverse->next; /*My key*/
	listint_t *store = NULL; 
	int key;

	while (next_transverse != NULL)
	{
		key = next_transverse->n; /*Key*/
		transverse = next_transverse->prev; /*'J'*/

		while ((transverse) && (transverse->n > key))
		{
			/* (transverse)->next->n = transverse->n; */
			/* transverse->n = arr[j] */
			/* (transverse->next->n)[j + 1] */ 
			store = transverse->next;
			transverse->next = transverse /* Bigger value*/



		}

		next_transverse = next_transverse->next;
	}

}