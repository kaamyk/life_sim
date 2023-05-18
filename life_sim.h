#ifndef LIFE_SIM_H
# define LIFE_SIM_H

# define WIN_HEIGHT 1000
# define WIN_LENGTH 1000

# include <stdlib.h>
# include <stdio.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <time.h>

typedef struct	s_window
{
	Display		*display;
	int			screen;
	Window		win;
	Window		root;
	XEvent		ev;
	GC			gc;
}				t_window;

typedef struct 	s_sim
{
	t_creature	*population;
	size_t		nb_creat;	
}				t_sim;

typedef struct	s_creature
{
	int8_t	size;
	int8_t	speed;
	XColor	color;
	time_t	last_meal;
}				t_creature;

//	MAIN.C

//	WINDOW.C
int		init_display(t_window *win);
int		destroy_display(t_window *win);

//	MOVE.C
void	move_up(size_t *y, t_creature c);
void	move_down(size_t *y, t_creature c);
void	move_right(size_t *x, t_creature c);
void	move_left(size_t *x, t_creature c);

#endif