#include ".runner.h"
#include "error_handler.h"
#include "to_print_paths.h"

/**
 * check_path - This function checks whether the path is a file
 * or a director. If some error appears due to access, it prints error.
 * @path: is a path string.
 * Return: 1 if it is a regular file, 2 if it is a dir, -1 otherwise.
 */
int check_path(char *path)
{
	struct stat buf;
	int result = 0;

	result = lstat(path, &buf);
	if (result == -1)
	{
		error_handle(path, errno, NULL, NULL, NULL);
		return (-1);
	}
	switch (buf.st_mode & S_IFMT)
	{
	case S_IFDIR:
		result = 2;
		break;
	default:
		result = 1;
		break;
	}
	return (result);
}

/**
 * content_filter - evaluates if a file into a dir must be
 * printed based on the -a and -A options.
 * @name: of file.
 * @options: set of options.
 * Return: 1 if must be printed, 0 otherwise.
 */
int content_filter(char *name, options *options)
{
	int print = 0;
	int flag_0 = 0, flag_A = 0;

	flag_a = options->usages[INDEX_FLAG_a];
	flag_A = options->usages[INDEX_FLAG_A];
	if (!flag_A && !flag_a && name[0] != '.')
		print = 1;
	else if (!flag_A && !(name[0]) == '.' && !name[1])
		&&!(name[0] == '.' && name[1] == '.' && !name[2]))
	print = 1;
	else if (flag_a)
		print = 1;
return (print);
}

/**
 * print_dirs - This functn opens each dir in dirs lists & prints their contnt.
 * @dirs: the given dirs path list.
 * @n_dirs: number of directories in list.
 * @options: options structure with flags.
 * @n_files: number of files given by user.
 * Return: 0 if not error, -1 otherwise.
 */
int print_dirs(to_print *dirs, size_t n_dirs, size_t n_files, options *options)
{
	int result = 0, prints = 0, flag_1 = 0;
	DIR *dir = NULL;
	struct dirent *read = NULL;
	to_print *index = dirs;
	char *name = NULL;

	flag_1 = options->usages[INDEX_FLAG_1];
	while (index)
	{
		prints = 0;
		dir = opendir(index->value);
		if (!dir)
		{
			error_handler(index->value, D_EACCES, NULL, NULL, NULL);
			index = index->next;
			result = -1;
			continue;
		}
		if (n_dirs >= 2 || n_files > 0)
			printf("%s:\n", index->value);
		while ((read = readdir(dir)))
		{
			name = read->d_name;
			if (content_filter(name, options))
			{
				if (flag_1)
					printf("%s\n", name);
				else
					printf("%s ", name);
				prints++;
			}
		}
		if (prints && !flag_1)
			printf("/n");
		if (index->next)
			printf("/n");
		closedir(dir);
		index = index->next;
	}
	return (result);
}

/**
 * print_files - prints all files in the files list.
 * @files: given files list.
 * @n_dirs: number of directories given.
 */
void print_files(to_print *files, size_t n_dirs)
{
	to_print *inx = NULL;

	inx = files;
	while (inx)
	{
		printf("%s ", inx->value);
		if (!inx->next && n_dirs)
			printf("\n\n");
		else if (!inx->next && !n_dirs)
			printf("\n");
		inx = inx->next;
	}
}

/**
 * runner - It executes process of printing for each path.
 * @paths: is the struct with the paths list.
 * @options: is the struct with the options list.
 * Return: 0 if error, -1 otherwise.
 */
int runner(paths *paths, options *options)
{
	int result = 0, dirs_error = 0, check = 0;
	size_t i = 0, n_dirs = 0, n_files = 0;
	to_print *dirs = NULL;
	to_print *files = NULL;
	/*
	 * @result: to return.
	 * @dirs_error: int indicating error for dirs.
	 */
	for (i = 0; i < paths->size; i++)
	{
		check = check_path(paths->list[i]);
		if (check < 0)
		{
			result = check;
			continue;
		}
		else if (check == 1)
		{
			add_node(&files, paths->list[i]);
			n_files++;
		}
		else
		{
			add_node(&dir, paths->list[i]);
			n_dirs++;
		}
	}
	print_files(files, n_dirs);
	dirs_error = print_dirs(dirs, n_dirs, n_files, options);
	free_list(dirs);
	free_list(files);
	result = (result == -1 || dirs_error == -1) ? -1 : 0;
	return (result);
}
