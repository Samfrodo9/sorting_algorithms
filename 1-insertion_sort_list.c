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

	listint_t *transverse = *list;
 	listint_t *next_transverse = transverse->next; /*My key*/
	listint_t *store = NULL; 
	int key;

	if ((*list)->next == NULL)
		return;

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
			transverse->next =  transverse;/* Bigger value*/
			transverse = store;

			transverse = transverse->prev ;/*loop till condition fails*/
		}
	}
	next_transverse = next_transverse->next;

}
/**
void swap(listint_t **a)
{
	listint_t *b = (*a)->next;
	listint_t *a_next, *a_prev, *b_next, *b_prev;

	a_prev = (*a)->prev;
	(*a)->prev = b;
	(*a)->next = b->next
}
*/
