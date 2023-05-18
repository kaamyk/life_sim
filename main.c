# include "life_sim.h"

void	generate_color(t_window *win)
{
	win->color.red = 225;
	win->color.green = 8281;
	win->color.blue = 42436;
	win->color.flags = DoRed | DoGreen | DoBlue;
	XAllocColor(win->display,
		DefaultColormap(win->display, DefaultScreen(win->display)),
		&win->color);
	XSetForeground(win->display, win->gc, win->color.pixel);
}

int	main(void)
{
	t_window	win;
	int			i;
	size_t		x;
	size_t		y;

	init_display(&win);
	i = 0;
	x = 20;
	y = 0;
	while (1)
	{
		//printf("i == %d\n", ++i);
		while (XPending(win.display) != 0)
			XNextEvent(win.display, &win.ev);
		generate_color(&win);
		XFillRectangle(win.display, win.win, win.gc,
			x, y, 20, 20);
		XFlush(win.display);
		usleep(33333);
		XClearArea(win.display, win.win, x, y, 20, 20, true);
		move_down(&y);
	}
	destroy_display(&win);
	return (0);
}
