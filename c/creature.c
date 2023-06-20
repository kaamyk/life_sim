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
	printf(">>>CHECK_CREATURE_POSITION<<<\n");
	size_t	i;

	i = 0;
	while (i < sim->nb_creat)
	{
		if (i != r
			&& (*x == sim->population[i]->x
				&& *y == sim->population[i]->y))
		{
			printf("i == %ld\n", i);
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
	creature->size = 1;
	creature->speed = 1;
	creature->last_meal = 0;
	creature->x = sim->population[r]->x + (10 * sim->population[r]->size);
	creature->y = sim->population[r]->y + (10 * sim->population[r]->size);
	check_creature_position(r + 1, &creature->x, &creature->y, sim);
	generate_color(win, creature);
	return (creature);
}

t_creature	**create_new_creature(t_window *win, t_sim *sim, uint8_t *c_eat, uint8_t len)
{
	printf("\t>>>CREATE_NEW_CREATURE<<<\n");
	//printf("len == %d\n", len);
	t_creature	**t;
	uint8_t		i;
	uint8_t		j;

	if (sim->nb_creat == 200)
		return (NULL);
	//printf("sin->nb_creat + len == %ld\n", sim->nb_creat + len);
	t = malloc(sizeof(t_creature *) * (sim->nb_creat + len + 1));
	sim->nb_creat += len;
	i = 0;
	j = 0;
	while (j < len)
	{
		while (i < sim->nb_creat)
		{
			t[i] = sim->population[i];
			if (c_eat[j] == i)
			{
				printf("Dans le if creation\n");
				++i;
				++j;
				t[i] = init_creature(win, sim, i - 1);
				break ;
			}
			++i;
		}
	}
	t[sim->nb_creat] = NULL;
	// i = 0;
	// while (i < sim->nb_creat)
	// {
	// 	t[i] = sim->population[i];
	// 	j = 0;
	// 	while (j < len)
	// 	{
	// 		if (c_eat[j] == i)
	// 		{
	// 			printf("Dans le if creation\n");
	// 			++i;
	// 			t[i] = init_creature(win, sim, i - 1);
	// 			break ;
	// 		}
	// 		++j;
	// 	}
	// 	++i;
	// }
	return (t);
}
