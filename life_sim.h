#ifndef LIFE_SIM_H
# define LIFE_SIM_H

# include <stdlib.h>
# include <stdio.h>
# include <X11/Xlib.h>
# include <X11/X.h>

typedef struct	s_window
{
	Display	*display;
	int		screen;
	Window	win;
	Window	root;
	XEvent	ev;
}				t_window;

//	MAIN.C


//	WINDOW.C
int	init_display(t_window *win);
int	destroy_display(t_window *win);

#endif