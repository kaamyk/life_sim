#include "life_sim.h"

int	init_display(t_window *win)
{
	win->display = XOpenDisplay(NULL);
	if (win->display == NULL)
	{
		printf("Display does not open\n");
		return (1);
	}
	win->screen = DefaultScreen(win->display);
	win->root = RootWindow(win->display, win->screen);
	win->win = XCreateSimpleWindow(win->display, win->root, 500, 500, 500, 500, 15,
			BlackPixel(win->display, win->screen), WhitePixel(win->display, win->screen));
	XMapWindow(win->display, win->win);
	return (0);
}

int	destroy_display(t_window *win)
{
	XDestroyWindow(win->display, win->root);
	XDestroyWindow(win->display, win->win);
	XCloseDisplay(win->display);
}
