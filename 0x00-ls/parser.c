#include "parser.h"

/**
 * open_paths - initializes paths struct.
 * Return: initialized paths struct.
 */
paths *open_paths()
{
	paths *new = NULL;
	int i = 0;

	new = (paths *) malloc(sizeof(paths));
	if (!new || !new->list)
	{
		perror("Error allocating paths struct.");
		return (NULL);
	}
	for (i = 0; i < 1024; i++)
		new->list[i] = NULL;
	new->size = 0;
	return (new);
}

/**
 * close_paths - It frees a given paths.
 * @paths: a given paths struct that has been opened.
 * Return: void.
 */
void close_paths(paths *paths)
{
	if (paths)
		free(paths);
}

/**
 * parser - Parses arguments given to the program;
 * paths and option are pointers to the caller function as it modifies values.
 * Note paths and options must be initialized structs.
 * Verifies the options using verify_options function and handles errors.
 * After deals with non '-' start strings, that are files.
 * If any files argument, the './' path is added as default.
 * @size: numbers in 'args' param - 1.
 * @args: contains arguments given by execution beginning on position one;
 * the first argument is the name of the program.
 * @paths: pointer to given paths structure in the caller function.
 * @options: pointer to given options structure in the caller function.
 * Returns: void.
 */
void parser(int size, char *args[], path **paths, options **options)
{
	int i, error = 0;

	if (!(*options) || !paths)
	{
		perror("Given struct is NULL\n");
		return;
	}
	*paths = open_paths();
	if (!*paths)
		return;
	for (i = 0; i < size; i++)
	{
		if (args[i][0] == '-' && args[i][1])
		{
			error = verify_options(options, &args[i][1]);
			if (error)
			{
				close_paths(*paths);
				exit(2);
			}
		}
		else
		{
			(*paths)->list[(*paths)->size] = args[i];
			(*paths)->size++;
		}
	}
	if (!(*paths)->size)
	{
		(*paths)->list[0] = "./";
		(*paths)->size++;
	}
}
