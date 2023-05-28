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

void	check_creature_position(int *x, int *y, t_sim *sim)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = sim->nb_creat;
	while (i <= j)
	{
		if (*x == sim->population[i]->x || *x == sim->population[j]->x)
		{
			*x = random() % WIN_LENGTH;
			i = 0;
			j = sim->nb_creat;
		}
		if (*y == sim->population[i]->y || *y == sim->population[j]->y)
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

t_creature	*init_creature(t_window *win, t_sim *sim)
{
	t_creature	*creature;

	creature = malloc (sizeof (t_creature) * 1);
	if (sim->nb_creat == 499)
		return (NULL);
	creature->size = sim->nb_creat;
	creature->speed = 1;
	creature->last_meal = 0;
	creature->x = random() % WIN_LENGTH;
	creature->y = random() % WIN_HEIGHT;
	check_creature_position(&creature->x, &creature->y, sim);
	generate_color(win, creature);
	return (creature);
}

t_creature	**create_new_creature(t_window *win, t_sim *sim)
{
	t_creature	**t;
	size_t		i;

	sim->nb_creat += 1;
	t = malloc(sizeof(t_creature *) * (sim->nb_creat + 1));
	if (t == NULL)
		return (NULL);
	t[sim->nb_creat] = NULL;
	i = 0;
	while (i < sim->nb_creat - 1)
	{
		t[i] = sim->population[i];
		++i;
	}
	t[i] = init_creature(win, sim);
	return (t);
}
