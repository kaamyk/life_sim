#include "life_sim.h"

bool	check_pixel(t_window *win, t_sim *sim)
{
	return (0);
}

t_food	*init_food(t_window *win, t_sim *sim, t_food *food)
{
	t_food	*t;
	int8_t	i;
	int8_t	j;

	t = malloc(sizeof(t_food) * 151);
	t_[150] = NULL;
	i = 0;
	sim->nb_food = 0;
	while (sim->nb_food < 150)
	{
		j = sim->nb_food - 1;
		t[sim->nb_food]->x = random() % WIN_LENGTH;
		t[sim->nb_food]->y = random() % WIN_HEIGHT;
		while (i <= j)
		{
			if (t[sim->nb_food]->x == t[i]->x || t[sim->nb_food]->y == t[i]->y
				|| t[sim->nb_food]->x == t[j]->x || t[sim->nb_food]->y == t[j]->y)
			{
				i = 0;
				j = sim->nb_food;
				t[sim->nb_food]->x = random() % WIN_LENGTH;
				t[sim->nb_food]->y = random() % WIN_HEIGHT;
			}
			else
			{
				++i;
				--j;
			}
		}
	}
	while (food->nb < 100)
	{
		//XDrawArc(Display *display, Drawable d, GC gc, int x, int y,
		//	unsigned int width, unsigned int height, int angle1, int angle2);
		XFillArc(win->display, win->win, win->gc,);
	}
}

void	draw_creature(t_window *win, t_sim *sim)
{
	size_t	i;

	i = 0;
	while (i < sim->nb_creat)
	{
		XFillRectangle(win->display, win->win, win->gc,
			sim->population[i]->x, sim->population[i]->y,
			10 * sim->population[0]->size,
			10 * sim->population[0]->size);
		++i;
	}
}

void	clear_creature(t_window *win, t_sim *sim)
{
	size_t	i;

	i = 0;
	while (sim->population[i])
	{
		XClearArea(win->display, win->win,
			sim->population[i]->x, sim->population[i]->y,
			10 * sim->population[i]->size, 10 * sim->population[i]->size, true);
		select_move(sim->population[i], random() % 5);
		++i;
	}
}
