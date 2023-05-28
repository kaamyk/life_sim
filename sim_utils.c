#include "life_sim.h"

void	draw_creature(t_window *win, t_sim *sim)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = sim->nb_creat;
	while (i <= j)
	{
		XFillRectangle(win->display, win->win, win->gc,
			sim->population[i]->x, sim->population[i]->y,
			10 * sim->population[0]->size,
			10 * sim->population[0]->size);
		XFillRectangle(win->display, win->win, win->gc,
			sim->population[j]->x, sim->population[j]->y,
			10 * sim->population[0]->size,
			10 * sim->population[0]->size);
		++i;
		if (j > 0)
			--j;
	}
}

void	clear_creature(t_window *win, t_sim *sim)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = sim->nb_creat;
	while (i <= j)
	{
		XClearArea(win->display, win->win,
			sim->population[i]->x, sim->population[i]->y,
			10 * sim->population[i]->size, 10 * sim->population[i]->size, true);
		XClearArea(win->display, win->win,
			sim->population[j]->x, sim->population[j]->y,
			10 * sim->population[j]->size, 10 * sim->population[j]->size, true);
		select_move(sim->population[i], random() % 5);
		++i;
		if (j > 0)
			--j;
	}
}
