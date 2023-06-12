#include "life_sim.h"

bool	eat(t_window *win, t_sim *sim, t_creature **p, t_food **f)
{
	bool	r;
	uint8_t	i;
	uint8_t	j;
	static uint8_t	eaten = 0;

	r = 0;
	i = 0;
	while (i < sim->nb_creat)
	{
		j = 0;
		while (j < sim->nb_food)
		{
			if (
				((f[j]->x >= p[i]->x && f[j]->x <= p[i]->x + (10 * p[i]->size))
					&& (f[j]->y >= p[i]->y - (10 * p[i]->size) && f[j]->y <= p[i]->y))
				|| ((f[j]->x + 3 >= p[i]->x && f[j]->x + 3 <= p[i]->x + (10 * p[i]->size))
					&& (f[j]->y >= p[i]->y - (10 * p[i]->size) && f[j]->y <= p[i]->y))
				|| ((f[j]->x >= p[i]->x && f[j]->x <= p[i]->x + (10 * p[i]->size))
					&& (f[j]->y - 3 >= p[i]->y - (10 * p[i]->size) && f[j]->y - 3 <= p[i]->y))
				|| ((f[j]->x + 3 >= p[i]->x && f[j]->x + 3 <= p[i]->x + (10 * p[i]->size))
					&& (f[j]->y - 3 >= p[i]->y - (10 * p[i]->size) && f[j]->y - 3 <= p[i]->y))
				)
			{
				printf("eaten = %d\n", ++eaten);
				printf("p->x = %ld | p->y = %ld | p->x + 10 = %ld | p->y - 10 = %ld\n",
					p[i]->x, p[i]->y, p[i]->x + 10, p[i]->y - 10);
				printf("f->x = %ld | f->y = %ld | f->x + 3 = %ld | f->y - 3 = %ld\n",
					f[j]->x, f[j]->y, f[j]->x + 3, f[j]->y - 3);
				XClearArea(win->display, win->win, f[j]->x,
					f[j]->y, 3, 3, true);
				f[j]->x = random() % WIN_LENGTH;
				f[j]->y = random() % WIN_HEIGHT;
				check_food_position(j, &f[j]->x, &f[j]->y, sim);
				r = 1;
			}
			++j;
		}
		++i;
	}
	return (r);
}

void	move_creature(t_window *win, t_sim *sim, t_creature **population)
{
	uint8_t	i;

	i = 0;
	while (population[i])
	{
		select_move(population[i], random() % 5);
		check_creature_position(i, &population[i]->x, &population[i]->y, sim);
		++i;
	}
	if (eat(win, sim, population, sim->food) == 1)
		sim->population = create_new_creature(win, sim);
}

void	ft_sim(t_window *win, t_sim *sim)
{
	//size_t	counter;

	//counter = 0;
	sim->food = init_food(win, sim);
	while (1)
	{
		//printf("counter == %ld\n", ++counter);
		while (XPending(win->display) != 0)
			XNextEvent(win->display, &win->ev);
		draw_creature(win, sim);
		draw_food(win, sim);
		XFlush(win->display);
		usleep(33333);
		clear_creature(win, sim);
		move_creature(win, sim, sim->population);
		// if (counter == 10)
		// {
		// 	counter = 0;
		// 	printf("Creating a new creature ... \n");
		// 	sim->population = create_new_creature(win, sim);
		// 	if (sim->population == NULL)
		// 		break ;
		// }
	}
	free(sim->food);
	free_population(sim->nb_creat, sim->population);
}
