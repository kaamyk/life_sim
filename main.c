#include "life_sim.h"

int	main(void)
{
	t_window	win;

	init_display(&win);
	while (XNextEvent(win.display, &win.ev) == 0)
		;
	destroy_display(&win);
	return (0);
}
