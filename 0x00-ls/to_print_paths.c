#include "to_print_paths.h"

/**
 * add_node - adds node in double linked list at end.
 * @head: head of list.
 * @value: value of node.
 * Return: pointer to new node.
 */
to_print *add_node(to_print **head, char *value);
{
	to_print *new = NULL, *index = (*head);
	/*
	 * new: ptr to_print struct in NULL.
	 * index: ptr to_print struct in *head value.
	 */
	if (!value)
		return (NULL);
	new = (to_print *) malloc(sizeof(to_print));
	if (!new)
		return (NULL);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	while (index->next)
		index = index->next;
	new->prev = index;
	index->next = new;
	return (new);
}

/**
 * free_list - free double linked list.
 * @head: head of list.
 * Return: nothing.
 */
void free_list(to_print *head)
{
	to_print *tmp = NULL;

	if (head)
	{
		while (head->next)
			head = head->next;
		while (head)
		{
			tmp = head->prev;
			free(head);
			head = tmp;
		}
	}
}

/**
 * remove_node - removes node in given position.
 * @head: head of list.
 * @index: index of new node.
 * Return: 1 if correct, -1 if failed.
 */
int remove_node(to_print **head, unsigned int index)
{
	to_print *actual;
	size_t size;
	/*
	 * @actual: ptr to_print struct var.
	 * @size: size_t var.
	 */
	actual = *head;
	size = 0;
	if (*head == NULL)
		return (-1);
	while (actual != NULL)
	{
		size++;
		actual = actual->next;
	}
	if (size < index + 1)
		return (-1);
	actual = *head;
	if (index == 0)
	{
		*head = actual->next;
		if (actual->next)
			actual->next->prev = NULL;
		actual->next = NULL;
		free(actual);
		return (1);
	}
	while (index--)
		actual = actual->next;
	actual->prev->next = actual->next;
	if (actual->next)
		actual->next->prev = actual->prev;
	free(actual);
	return (1);
}
