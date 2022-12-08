#ifndef TO_PRINT_PATHS_H
#define TO_PRINT_PATHS_H

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

/**
 * struct dlistint - doubly linked list.
 * @value: dirent value.
 * @prev: points to previous node.
 * @next: points to next node.
 * Description: doubly linked list node structure.
 */
typedef struct dlistint
{
	char *value;
	struct dlistint *prev;
	struct dlistint *next;
} to_print;

/**
 * add_node - adds node in double linked list at end.
 * @head: head of list.
 * @value: value of node.
 * Return: pointer to new node.
 */
to_print *add_node(to_print **head, char *value);

/**
 * free_list - free double linked list.
 * @head: head of list.
 * Return: nothing.
 */
void free_list(to_print *head);

/**
 * sort_list - sort linked list in place.
 * @head: head of list.
 * @by: criterium to be sorted, e.g. 'S' to sort by size
 * 't' to sort by time or, 'r' to reverse list.
 */
void sort_list(to_print **head, char by);

#endif
