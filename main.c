# include "life_sim.h"

void	generate_color(t_window *win)
{
	win->color.red = random() % 65536;
	win->color.green = random() % 65536;
	win->color.blue = random() % 65536;
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
	uint16_t	x;
	uint16_t	y;

	init_display(&win);
	i = 0;
	x = 20;
	y = 0;
	while (1)
	{
		printf("i == %d\n", ++i);
		while (XPending(win.display) != 0)
			XNextEvent(win.display, &win.ev);
		generate_color(&win);
		XFillRectangle(win.display, win.win, win.gc,
			x, y, 30, 30);
		XFlush(win.display);
		usleep(16666);
		XClearArea(win.display, win.win, x, y, 30, 30, true);
		y += 5;
		if (y >= 500)
		{
			x += 30;
			y = 0;
		}
	}
	destroy_display(&win);
	return (0);
}
