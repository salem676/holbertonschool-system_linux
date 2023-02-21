#include "signals.h"

int sigset_init(sigset_t *set, int *signals)
{
	for (sigemptyset(set); *signals; signals++)
		if (sigaddset(set, *signals))
			return (-1);
	return (0);
}

int signals_block(int *signals)
{
	sigset_t set;

	if (sigset_init(&set, signals) ||
		sigprocmask(SIG_BLOCK, &set, NULL))
		return (-1);
	return (0);
}
