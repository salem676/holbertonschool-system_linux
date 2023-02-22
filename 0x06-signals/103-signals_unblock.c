#include "signals.h"

/**
 * sigset_init - method
 * @set: ptr to sigset_t
 * @signals: ptr to int
 * Return: -1 or 0
 **/

int sigset_init(sigset_t *set, int *signals)
{
	for (sigemptyset(set); *signals; signals++)
		if (sigaddset(set, *signals))
			return (-1);
	return (0);
}

/**
 * signals_unblock - playing pocker
 * @signals: ptr to int
 * Return: -1 or 0
 **/
int signals_unblock(int *signals)
{
	sigset_t set;

	if (sigset_init(&set, signals) ||
		sigprocmask(SIG_UNBLOCK, &set, NULL))
		return (-1);
	return (0);
}
