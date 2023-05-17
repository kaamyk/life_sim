# include "life_sim.h"

int	main(void)
{
	t_window	win;
	bool		b;

	init_display(&win);
	b = false;
	while (1)
	{
		XNextEvent(win.display, &win.ev);
		b = !b;
		if (b == true)
			XClearWindow(win.display, win.win);
		else if (win.ev.type == Expose)
			XFillRectangle(win.display, win.win, DefaultGC(win.display, win.screen),
				10, 10, 10, 10);
	}
	destroy_display(&win);
	return (0);
}
