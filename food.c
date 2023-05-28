#include "life_sim.h"

void	draw_food(t_window *win, t_sim *sim, t_food *t)
{
	int8_t	i;
	int8_t	j;

	while (i < 150)
	{
		//XDrawArc(Display *display, Drawable d, GC gc, int x, int y,
		//	unsigned int width, unsigned int height, int angle1, int angle2);
		XFillArc(win->display, win->win, win->gc, sim->food[i]->x,
			sim->food[i]->display, 5, 5, 0, 360 * 64);
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

void	check_food_position(size_t *x, size_t *y, t_window *win, t_sim *sim)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = sim->nb_food;
	while (i <= j && sim->nb_food != 1)
	{
		if (*x == sim->food[i]->x || *x == sim->food[j]->x)
		{
			*x = random() % WIN_LENGTH;
			i = 0;
			j = sim->nb_creat;
		}
		if (*y == sim->food[i]->y || *y == sim->food[j]->y)
		{
			*y = random() % WIN_HEIGHT;
			i = 0;
			j = sim->nb_creat;
		}
		++i;
		if (j > 0)
			--j;
	}
}

t_food	*init_food(t_window *win, t_sim *sim)
{
	t_food	*t;

	t = malloc(sizeof(t_food) * 151);
	t_[150] = NULL;
	sim->nb_food = 0;
	while (sim->nb_food < 150)
	{
		printf("sim->food == %ld\n", sim->food);
		t->x = random() % WIN_LENGTH;
		t->y = random() % WIN_HEIGHT;
		generate_position(win, zim, t);
		draw_food(win, sim);
		sim->nb_food += 1;
	}
	return (t);
}
