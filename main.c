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

int	main(void)
{
	t_window	win;
	t_sim		sim;
	size_t		i;
	size_t		counter;

	counter = 0;
	init_display(&win);
	create_new_creature(&win, &sim);
	while (1)
	{
		printf("counter == %ld\n", ++counter);
		i = 0;
		while (XPending(win.display) != 0)
			XNextEvent(win.display, &win.ev);
		XFillRectangle(win.display, win.win, win.gc,
			creature.x, creature.y, 10 * creature.size, 10 * creature.size);
		XFlush(win.display);
		usleep(33333);
		XClearArea(win.display, win.win, creature.x, creature.y,
			10 * creature.size, 10 * creature.size, true);
		while (sim.population[i])
		{
			select_move(&sim.population[i], random() % 5);
			++i;
		}
		if (counter != 0 && counter % 100 == 0)
			create_new_creature(&sim);
	}
	destroy_display(&win);
	return (0);
}
