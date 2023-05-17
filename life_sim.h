#ifndef LIFE_SIM_H
# define LIFE_SIM_H

# include <stdlib.h>
# include <stdio.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct	s_window
{
	Display		*display;
	int			screen;
	Window		win;
	Window		root;
	XEvent		ev;
	XFontStruct	*font;
	GC			gc;
}				t_window;

//	MAIN.C

//	WINDOW.C
void	expose(t_window *win);
int	init_display(t_window *win);
int	destroy_display(t_window *win);

#endif