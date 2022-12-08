#ifndef RUNNER_H
#define RUNNER_H

#include "options.h"
#include "parser.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * runner - Executes process of printing each of the paths.
 * @paths: struct with paths list.
 * @options: struct with options list.
 * Return: 0 if correct, -1 otherwise.
 */
int runner(paths *paths, options *options);

/**
 * check_path - this functions checks whether path
 * is a file or a directive. If some error appears,
 * prints.
 * @path: path string.
 * Return: 0 if correct, -1 otherwise.
 */
int check_path(char *path);

struct dirent **filter(char *path);

struct dirent **order(struct dirent **files);

int format(struct dirent **files);

#endif
