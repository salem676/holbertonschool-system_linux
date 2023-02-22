#include "signals.h"

/**
 * sigset_init - function for init
 * @set: sigset_t param ptr
 * @signals: int var prm ptr
 **/
int sigset_init(sigset_t *set, int *signals)
{
	for (sigemptyset(set); *signals; signals++)
		if (sigaddset(set, *signals))
			return (-1);
	return (0);
}

/**
 * signals_block - function block
 * @signals: int var prm ptr
 **/
int signals_block(int *signals)
{
	sigset_t set;

	if (sigset_init(&set, signals) ||
		sigprocmask(SIG_BLOCK, &set, NULL))
		return (-1);
	return (0);
}
