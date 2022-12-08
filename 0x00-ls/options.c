#include "options.h"
#include "error_handler.h"

/**
 * close_options - This function frees allocated options pointer.
 * @options: opened data structure.
 */
void close_options(options *options)
{
	free(options);
}

/**
 * verify_options - Verifies given options arguments.
 * if one of the chars is not an alias in options array,
 * it exits program with error message.
 * @options: supported options.
 * @input_options: input arguments given by user
 * to use in command, must be null terminated string.
 * Return: 0 if correct; 1 if error.
 */
int verify_options(options **options, const char *input_options)
{
	int i, j, found = 0;

	if (!options || !(*options) || !(*options)->aliases)
	{
		perror("error verifying flags");
		exit(98);
	}
	for (i = 0; input_options[i]; i++)
	{
		found = 0;
		for (j = 0; (*options)->aliases[j] && !found; j++)
		{
			if (input_options[i] == (*options)->aliases[j])
				found = 1;
			if (found)
			{
				if ((*options)->aliases[j] == 'S')
					(*options)->usages[6] = 0;
				else if ((*options)->aliases[j] == 't')
					(*options)->usages[5] = 0;
				(*options)->usages[j] = 1;
			}
		}
		if (!found)
		{
			error_handler(&input_options[i], INVALID_OPTION, *options, NULL, NULL);
			return (1);
		}
	}
	return (0);
}
/**
 * init_options - This function initialices instance of options struct.
 * If there is and error in allocation, exit and print erro.
 * Return: allocated options pointer.
 */
options *init_options()
{
	int i = 0;
	options *new = NULL;
	/*
	 * @i: counter.
	 * @new: ptr to options to NULL.
	 */
	new = (options *) malloc(sizeof(options));
	if (!new)
	{
		perror("Error in options struct allocation");
		exit(98);
	}
	new->aliases = "1laArStR\0";
	for (i = 0; i < NUMBER_FLAGS; i++)
		new->usages[i] = 0;
	return (new);
}
