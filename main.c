# include "life_sim.h"

int	main(void)
{
	t_window	win;
	bool		b;
	int			i;

	init_display(&win);
	b = false;
	i = 0;
	while (1)
	{
		printf("i == %d\n", ++i);
		if (XPending(win.display) == 0)
			XNextEvent(win.display, &win.ev);
		b = !b;
		if (b == true)
		{
			XClearArea(win.display, win.win, 10, 10, 10, 10, true);
		}
		else if (win.ev.type == KeyPress)
		{
			XFillRectangle(win.display, win.win, win.gc,
				10, 10, 10, 10);
		}
		usleep(1000);
	}
	destroy_display(&win);
	return (0);
}
