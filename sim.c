#include "life_sim.h"

bool	eat(t_window *win, t_sim *sim, t_creature *p, t_food **f)
{
	bool	r;
	uint8_t	i;

	r = 0;
	i = 0;
	while (i < sim->nb_food)
	{
		if (((f[i]->x >= p->x && f[i]->x <= p->x + (10 * p->size))
				&& (f[i]->y >= p->y - (10 * p->size) && f[i]->y <= p->y))
			|| ((f[i]->x + 3 >= p->x && f[i]->x + 3 <= p->x + (10 * p->size))
				&& (f[i]->y >= p->y - (10 * p->size) && f[i]->y <= p->y))
			|| ((f[i]->x >= p->x && f[i]->x <= p->x + (10 * p->size))
				&& (f[i]->y - 3 >= p->y - (10 * p->size) && f[i]->y - 3 <= p->y))
			|| ((f[i]->x + 3 >= p->x && f[i]->x + 3 <= p->x + (10 * p->size))
				&& (f[i]->y - 3 >= p->y - (10 * p->size) && f[i]->y - 3 <= p->y)))
		{
			XClearArea(win->display, win->win, f[i]->x,
				f[i]->y, 3, 3, true);
			f[i]->x = random() % WIN_LENGTH;
			f[i]->y = random() % WIN_HEIGHT;
			check_food_position(i, &f[i]->x, &f[i]->y, sim);
			r = 1;
		}
		++i;
	}
	return (r);
}

void	move_creature(t_window *win, t_sim *sim, t_creature **population)
{
	uint8_t	*c_eat = malloc(sizeof(uint8_t) * sim->nb_creat);
	uint8_t	i;
	uint8_t	j;

	c_eat = memset(c_eat, 0, sizeof(eat));
	i = 0;
	j = 0;
	while (population[i])
	{
		//select_move(population[i], random() % 5);
		select_move(population[i], 1);
		check_creature_position(i, &population[i]->x, &population[i]->y, sim);
		if (eat(win, sim, population[i], sim->food))
			c_eat[j++] = i;
		++i;
	}
	//if (eat(win, sim, population, sim->food) == 1)
	//	sim->population = create_new_creature(win, sim);
	if (j > 0)
		sim->population = create_new_creature(win, sim, c_eat, j);
	free(c_eat);
}

void	ft_sim(t_window *win, t_sim *sim)
{
	sim->food = init_food(win, sim);
	while (1)
	{
		while (XPending(win->display) != 0)
			XNextEvent(win->display, &win->ev);
		draw_creature(win, sim);
		draw_food(win, sim);
		XFlush(win->display);
		usleep(33333);
		clear_creature(win, sim);
		move_creature(win, sim, sim->population);
	}
	free(sim->food);
	free_population(sim->nb_creat, sim->population);
}
