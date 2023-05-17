#include "life_sim.h"

void	expose(t_window *win)
{
	XDrawString(win->display, win->root, win->gc, 10, 30, "Bonjour !", 14);
}

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
			BlackPixel(win->display, win->screen),
			WhitePixel(win->display, win->screen));
	win->gc = XDefaultGC(win->display, win->screen);
	XSelectInput(win->display, win->win, KeyPressMask);
	XSetBackground(win->display, win->gc, 100);
	XStoreName(win->display, win->win, "Life Simulation");
	XMapWindow(win->display, win->win);
	//XFlush(win->display);
	return (0);
}

int	destroy_display(t_window *win)
{
	XFreeGC(win->display, win->gc);
	XDestroyWindow(win->display, win->root);
	XDestroyWindow(win->display, win->win);
	XCloseDisplay(win->display);
}
