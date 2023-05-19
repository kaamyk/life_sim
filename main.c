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
	sim->population[0]->size = 1;
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
	//t_creature	**tmp;
	size_t		i;
	size_t		counter;

	counter = 0;
	ft_signal();
	init_display(&win);
	init_sim(&win, &sim);
	while (1)
	{
		printf("counter == %ld\n", ++counter);
		while (XPending(win.display) != 0)
			XNextEvent(win.display, &win.ev);
		i = 0;
		while (i < sim.nb_creat)
		{
			XFillRectangle(win.display, win.win, win.gc,
				sim.population[i]->x, sim.population[i]->y,
				10 * sim.population[0]->size,
				10 * sim.population[0]->size);
			++i;
		}
		XFlush(win.display);
		usleep(33333);
		i = 0;
		while (sim.population[i])
		{
			XClearArea(win.display, win.win,
				sim.population[i]->x, sim.population[i]->y,
				10 * sim.population[i]->size, 10 * sim.population[i]->size, true);
			select_move(sim.population[i], random() % 5);
			++i;
		}
		if (counter > 0 && counter % 10 == 0)
		{
			//tmp = sim.population;
			sim.population = create_new_creature(&win, &sim);
			//free_population(sim.nb_creat, tmp);
			printf("population size == %d\n", sim.population[0]->size);
			//printf("tmp == %p\n", tmp);
			printf("population == %p\n", sim.population);
		}
	}
	destroy_display(&win);
	return (0);
}
