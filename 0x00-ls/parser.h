#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include "./options.h"

/**
 * struct paths_struct - Struct that contains files path.
 * @list: contains given paths.
 * @size: current number op paths in the list member.
 */
typedef struct paths_struct
{
        char *list[1024];
        size_t size;
} paths;

/**
 * open_paths - initializes paths struct.
 * Return: initialized paths struct.
 */
paths *open_paths();

/**
 * close_paths - It frees a given paths.
 * @paths: a given paths struct that has been opened.
 * Return: void.
 */
void close_paths(paths *paths);

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
void parser(int size, char *args[], path **paths, options **options);

#endif
