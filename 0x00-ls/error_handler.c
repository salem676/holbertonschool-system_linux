#include "error_handler.h"

/**
 * invalid _option_error - This function prints the ls error when
 * wrong or not implemented option is given.
 * @item: bad char option.
 * @options: options structure to be freed.
 */
void invalid_option_error(const char item, options *options)
{
	fprintf(stderr, "hls: invalid option -- '%c'\n", item);
	fprintf(stderr, "try 'hls --help' for more information.\n");
	close_options(options);
}

/**
 * not_permissions_error - This function prints the ls error when
 * the path contains privilege greater than the current user.
 * @item: path.
 */
void not_permissions_error(const char *item)
{
	fprintf(stderr, "hls: cannot access %s: Permission denied\n", item);
}

/**
 * not_access_error - This functions prints the ls error when
 * path does not exist.
 * @item: path.
 */
void not_access_error(const char *item)
{
	fprintf(stderr, "hls: cannot access %s: No such file or directory\n", item);
}

/**
 * not_allow_to_open - this functions prints ls error when
 * permissions are incorrect.
 * @item: path.
 */
void not_allow_to_open(const char *item)
{
	fprintf(stderr, "hls: cannot open directory %s: Permission denied\n", item);
}

/**
 * error_handler - This function prints errors to the stderr based on
 * and supported error code.
 * @item: that provoked issue.
 * @code: code of the error.
 * @options: options structure, to be freed.
 * @paths: paths structure, to be freed.
 * @list: to_print structure, to be freed.
 */
void error_handler(const char *item, int code, options *options
		   , path *paths, to_print *list)
{
	(void) paths;
	(void) list;
	switch (code)
	{
	case INVALID_OPTION:
		invalid_option_error(item[0]);
		break;
	case EACCES:
		not_permissions_error(item);
		break;
	case ENOENT:
		not_access_error(item);
		break;
	case D_EACCES:
		not_allow_to_open(item);
	}
}
