#include "life_sim.h"

void	int_signal(int sig, siginfo_t *a, void *sim)
{
	(void) a;
	if (sig == SIGINT)
	{
		printf("\t>>> Dans int_signal <<<\n");
		free_population(((t_sim *)sim)->nb_creat, ((t_sim *)sim)->population);
	}
	exit (sig);
}

void	ft_signal(void)
{
	t_sigaction	sig;

	sig.sa_sigaction = int_signal;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGINT, &sig, 0);
}
