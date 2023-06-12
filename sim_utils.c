#include "life_sim.h"

void	draw_creature(t_window *win, t_sim *sim)
{
	size_t	i;

	i = 0;
	while (i < sim->nb_creat)
	{
		XFillRectangle(win->display, win->win, win->gc,
			sim->population[i]->x, sim->population[i]->y,
			10 * sim->population[i]->size,
			10 * sim->population[i]->size);
		++i;
	}
}

void	clear_creature(t_window *win, t_sim *sim)
{
	size_t	i;

	i = 0;
	while (i < sim->nb_creat)
	{
		XClearArea(win->display, win->win,
			sim->population[i]->x, sim->population[i]->y,
			10 * sim->population[i]->size, 10 * sim->population[i]->size, true);
		++i;
	}
}

void	draw_food(t_window *win, t_sim *sim)
{
	uint8_t	i;

	i = 0;
	while (i < sim->nb_food)
	{
		XFillRectangle(win->display, win->win, win->gc,
			sim->food[i]->x, sim->food[i]->y, 3, 3);
		++i;
	}
}

void	clear_food(t_window *win, t_sim *sim)
{
	size_t	i;

	i = 0;
	while (sim->food[i])
	{
		XClearArea(win->display, win->win,
			sim->population[i]->x, sim->population[i]->y,
			10 * sim->population[i]->size, 10 * sim->population[i]->size, true);
		select_move(sim->population[i], random() % 5);
		++i;
	}
}
