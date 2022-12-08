#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdlib.h>
#include <stdio.h>
#define INVALID_OPTION 5

#define NUMBER_FLAGS 8
#define INDEX_FLAG_1 0
#define INDEX_FLAG_l 1
#define INDEX_FLAG_a 2
#define INDEX_FLAG_A 3
#define INDEX_FLAG_r 4
#define INDEX_FLAG_S 5
#define INDEX_FLAG_t 6
#define INDEX_FLAG_R 7

/**
 * struct option_struct - contains aliases of supported flags,
 * and contains options to execute.
 * @aliases: string with chars that represent options.
 * @usages: binary array in which every position corresponds
 * to position of a char in aliases.
 */
typedef struct option_struct
{
char *aliases;
short usages[8];
} options;

/**
 * init_options - This function initializes an instance of options struct.
 * If error in allocation, exits and prints erro.
 * Return: allocated options pointer.
 */
options *init_options();

/**
 * close_options - This function frees allocated options pointer.
 * @options: initialized options structure.
 */
void close_options(options *options);

/**
 * verify_options - Verifies if given options arguments are correct.
 * If one of the chars is not an alias in the options array, it
 * exits program with error message.
 * @options: supported options.
 * @input_options: input arguments given by the user
 * to use in command; must be a null terminated string
 * Return: 0 if correct, 1 if error.
 */
int verify_options(options **options, const char *input_options);

#endif
