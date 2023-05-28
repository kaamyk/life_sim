#include "life_sim.h"

void	ft_sim(t_window *win, t_sim *sim)
{
	size_t	counter;

	counter = 0;
	sim->food = init_food(win, sim);
	while (1)
	{
		//printf("counter == %ld\n", ++counter);
		while (XPending(win->display) != 0)
			XNextEvent(win->display, &win->ev);
		draw_creature(win, sim);
		XFlush(win->display);
		usleep(33333);
		clear_creature(win, sim);
		if (counter == 10)
		{
			counter = 0;
			printf("Creating a new creature ... \n");
			sim->population = create_new_creature(win, sim);
			if (sim->population == NULL)
				break ;
		}
		++counter;
	}
	free(sim->food);
	free_population(sim->nb_creat, sim->population);
}
