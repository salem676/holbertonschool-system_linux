#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - Program that reproduces the GNU objdump command
 * @argc: How many arguments from OS command line
 * @argv: The arguments from OS command line
 * @env: The environment from shell
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv, char **env)
{
	char *av[] = {"./hobjdump", "-sf", "", NULL};

	(void)argc;
	av[2] = argv[1];
	if (execve("/usr/bin/objdump", av, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
