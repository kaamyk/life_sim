#include "life_sim.h"

void	check_food_position(uint8_t r, size_t *x, size_t *y, t_sim *sim)
{
	size_t	i;

	i = 0;
	while (i < sim->nb_food)
	{
		if (i != r
			&& (*x == sim->food[i]->x && *y == sim->food[i]->y))
		{
			*x = random() % WIN_LENGTH;
			*y = random() % WIN_HEIGHT;
			i = 0;
		}
		++i;
	}
}

t_food	**init_food(t_window *win, t_sim *sim)
{
	t_food	**t;
	uint8_t	i;

	t = malloc(sizeof(t_food *) * 151);
	t[150] = NULL;
	sim->food = t;
	sim->nb_food = 0;
	i = 0;
	while (sim->nb_food < 150)
	{
		t[i] = malloc(sizeof(t_food));
		t[i]->x = random() % WIN_LENGTH;
		t[i]->y = random() % WIN_HEIGHT;
		if (i != 0)
			check_food_position(i, &t[i]->x, &t[i]->y, sim);
		draw_food(win, sim);
		sim->nb_food += 1;
		++i;
	}
	return (t);
}
