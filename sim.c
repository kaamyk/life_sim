#include "life_sim->h"

void	ft_sim(t_window *win, t_sim *sim)
{
	while (1)
	{
		//printf("counter == %ld\n", ++counter);
		while (XPending(win->display) != 0)
			XNextEvent(win->display, &win->ev);
		draw_creature(win, sim);
		XFlush(win->display);
		usleep(33333);
		clear_creature(win, sim);
		if (counter > 0 && counter % 10 == 0)
		{
			printf("Creating a new creature ->->->\n");
			sim->population = create_new_creature(&win, &sim);
			if (sim->population == NULL)
				break ;
		}
		++counter;
	}
}
