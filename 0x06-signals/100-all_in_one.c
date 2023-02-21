#include "signals.h"

void print_gotcha(int signal, siginfo_t *info, void *name)
{
	(void)signal;
	(void)name;
	psiginfo(info, "Caught");
}

void all_in_one(void)
{
	struct sigaction act;
	int signal;

	memset(&act, 0, sizeof(act));
	act.sa_flags |= SA_SIGINFO;
	act.sa_sigaction = print_gotcha;
	for (signal = SIGHUP; signal <= SIGRTMAX; signal++)
		sigaction(signal, &act, NULL);
}
