# include "life_sim.h"

void	generate_color(t_window *win, t_creature *creature)
{
	creature->color.red = 65535;
	creature->color.green = 65535;
	creature->color.blue = 65535;
	creature->color.flags = DoRed | DoGreen | DoBlue;
	XAllocColor(win->display,
		DefaultColormap(win->display, DefaultScreen(win->display)),
		&creature->color);
	XSetForeground(win->display, win->gc, creature->color.pixel);
}

void	init_sim(t_window *win, t_sim *sim)
{
	sim->population = malloc(sizeof(t_creature *) * 2);
	sim->population[0] = malloc (sizeof (t_creature));
	sim->population[0]->size = random() % 10;
	sim->population[0]->speed = 1;
	sim->population[0]->last_meal = 0;
	sim->population[0]->x = random() % WIN_LENGTH;
	sim->population[0]->y = random() % WIN_HEIGHT;
	generate_color(win, sim->population[0]);
	sim->population[1] = NULL;
	sim->nb_creat = 1;
}

int	main(void)
{
	t_window	win;
	t_sim		sim;

	ft_signal();
	init_display(&win);
	init_sim(&win, &sim);
	ft_sim(&win, &sim);
	destroy_display(&win);
	return (0);
}
