#include "life_sim.h"

void	move_up(size_t *y, t_creature c)
{
	*y -= 5 * c.speed;
	if (*y < 0)
		*y = WIN_HEIGHT;
}

void	move_down(size_t *y, t_creature c)
{
	*y += 5 * c.speed;
	if (*y >= WIN_HEIGHT)
		*y = 0;
}

void	move_right(size_t *x, t_creature c)
{
	*x += 5 * c.speed;
	if (*x >= WIN_LENGTH)
		*x = 0;
}

void	move_left(size_t *x, t_creature c)
{
	*x -= 5 * c.speed;
	if (*x < 0)
		*x = WIN_LENGTH;
}
