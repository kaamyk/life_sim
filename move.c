#include "life_sim.h"

void	move_up(t_creature *c)
{
	if (c->y <= 1)
		c->y = WIN_HEIGHT - (c->y - 2);
	else
		c->y -= 2 * c->speed;
}

void	move_down(t_creature *c)
{
	c->y += 2 * c->speed;
	if (c->y >= WIN_HEIGHT)
		c->y = 0;
}

void	move_right(t_creature *c)
{
	c->x += 2 * c->speed;
	if (c->x >= WIN_LENGTH)
		c->x = 0;
}

void	move_left(t_creature *c)
{
	if (c->x <= 1)
		c->x = WIN_LENGTH - (c->x - 2);
	else
		c->x -= 2 * c->speed;
}

void	select_move(t_creature *c, int8_t m)
{
	//printf("m == %d\n", m);
	switch (m)
	{
		case 0:
			move_up(c);
			break ;
		case 1:
			move_down(c);
			break ;
		case 2:
			move_right(c);
			break ;
		case 3:
			move_left(c);
			break ;
		case 4:
			break;
	}
}
