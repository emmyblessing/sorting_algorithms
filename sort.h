#ifndef sort_h
#define sort_h
#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void swap(int *xp, int *yp);

/**
 * struct listint_s - Doubly linked list node
 *
 * @number: Integer stored in the node
 * @previous: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int number;
	struct listint_s *previous;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
/*Selection sort*/
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
#endif
