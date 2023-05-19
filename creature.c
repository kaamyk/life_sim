#include "life_sim.h"

void	free_population(t_creature *creature)
{
	size_t	i;

	if (creature == NULL)
		return ;
	while (creature[i])
	{
		free(creature[i]);
		++i;
	}
}

void	free_sim(t_sim *sim)
{
	if (sim == NULL)
		return ;
	free_population(sim->population);
	free(sim);
	sim = NULL;
}

void	check_position(t_creature *creature, t_sim *sim)
{
	size_t	i;

	i = 0;
	while (sim->population[i])
	{
		if (creature->x == sim->population[i]->x)
		{
			creature->x = random() % WIN_LENGTH;
			i = 0;
		}
		if (creature->y == sim->population[i]->y)
		{
			creature->y == random() % WIN_HEIGHT;
			i = 0;
		}
		else
			++i;
	}
}

t_creature	*init_creature(t_sim *sim)
{
	t_creature	*creature;

	if (sim->nb_creat == 499)
		return (NULL);
	creature->size = 1;
	creature->speed = 1;
	creature->last_meal = 0;
	creature->x = random() % WIN_LENGTH;
	creature->y = random() % WIN_HEIGHT;
	check_position(creature, sim);
	return (creature);
}

void	join_creature(t_creature *creature, t_sim *sim)
{
	t_creature	*t;
	size_t		i;

	t = malloc(sizeof(t_creature) * sim->nb_creat + 1);
	sim->creature[nb_creat - 1] = NULL;
	i = 0;
	while (i < sim->nb_creat - 1)
		t[i] = sim->population[i];
	t[i] = init_creature(sim);
}

void	create_new_creature(t_window *win, t_sim *sim)
{
	t_creature	*t;

	t = join_creature(creature, sim);
	free_sim(sim);
	sim = t;
	generate_color(&win, &creature);
	free_population(t);
}
