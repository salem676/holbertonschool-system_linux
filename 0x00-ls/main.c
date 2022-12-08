#include "./options.h"
#include "./parser.h"
#include "./runner.h"

/**
 * main - function.
 * @argc: size of the argv array.
 * @argv: array with commands.
 * Return: 0 for success, other number otherwise.
 */
int main(int argc, char *argv[])
{
	int result = 0;
	path *paths = NULL;
	option *options = NULL;
	/*
	 * @result: var.
	 * @paths: ptr var to path struct instance.
	 * @options: ptr var to options struct instance.
	 */
	options = init_options();
	parser(argc - 1, &argv[1], &paths, &options);
	result = runner(paths, options);
	close_paths(paths);
	close_options(options);
	if (result == -1)
	{
		return (2);
	}
	return (0);
}
