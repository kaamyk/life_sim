#include "life_sim.h"

void	free_population(size_t nb_creat, t_creature **population)
{
	size_t	i;

	if (population == NULL)
		return ;
	i = 0;
	while (i < nb_creat)
	{
		free(population[i]);
		++i;
	}
	population = NULL;
}

void	check_creature_position(uint8_t r, size_t *x, size_t *y, t_sim *sim)
{
	size_t	i;

	i = 0;
	while (i < sim->nb_creat)
	{
		if (i != r
			&& (*x == sim->population[i]->x && *y == sim->population[i]->y))
		{
			*x = random() % WIN_LENGTH;
			*y = random() % WIN_HEIGHT;
			i = 0;
		}
		++i;
	}
}

t_creature	*init_creature(t_window *win, t_sim *sim, uint8_t r)
{
	t_creature	*creature;

	creature = malloc (sizeof (t_creature) * 1);
	if (sim->nb_creat == 499)
		return (NULL);
	creature->size = 1;
	creature->speed = 1;
	creature->last_meal = 0;
	creature->x = random() % WIN_LENGTH;
	creature->y = random() % WIN_HEIGHT;
	check_creature_position(r, &creature->x, &creature->y, sim);
	generate_color(win, creature);
	return (creature);
}

t_creature	**create_new_creature(t_window *win, t_sim *sim)
{
	t_creature	**t;
	uint8_t		i;

	t = malloc(sizeof(t_creature *) * (sim->nb_creat + 2));
	i = 0;
	while (i < sim->nb_creat)
	{
		t[i] = sim->population[i];
		++i;
	}
	printf("Apres copy i == %d\n", i);
	sim->nb_creat += 1;
	t[i] = init_creature(win, sim, i);
	++i;
	t[sim->nb_creat] = NULL;
	return (t);
}
