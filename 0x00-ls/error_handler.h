#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <stdio.h>
#include "./parser.h"
#include "./options.h"
#include "./to_print_paths.h"
#include <sys/stat.h>
#include <errno.h>

#define D_EACCES (EACCES + 1)

void error_handler(const char*, int, options *, paths *, to_print *);

/**
 * invalid_option_error - This function prints ls error when wrong
 * or not implemented option is given by user. For instance '--' option
 * @item: bad char option.
 * @options: options struture to be freed.
 */
void invalid_option_error(char item, options *options);

/**
 * not_permissions_error - This function prints ls error when path
 * contains privilege greater than current user.
 * @item: path.
 */
void not_permissions_error(const char *item);

/**
 * not_access_error - This functions prints ls error when path
 * is not existent.
 * @item: path.
 */
void not_access_error(const char *item);
#endif
