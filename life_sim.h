#ifndef LIFE_SIM_H
# define LIFE_SIM_H

# define WIN_HEIGHT 1000
# define WIN_LENGTH 1000
# define BASICS

# include <stdlib.h>
# include <stdio.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <time.h>
# include <signal.h>

typedef struct sigaction t_sigaction;

typedef struct	s_window
{
	Display		*display;
	int			screen;
	Window		win;
	Window		root;
	XEvent		ev;
	GC			gc;
}				t_window;

typedef struct	s_creature
{
	int8_t	size;
	int8_t	speed;
	XColor	color;
	int		x;
	int		y;
	time_t	last_meal;
}				t_creature;

typedef struct	s_food
{
	size_t	x;
	size_t	y;
}				t_food;

typedef struct 	s_sim
{
	t_creature	**population;
	t_food		*food;
	size_t		nb_food;
	size_t		nb_creat;	
}				t_sim;

//	MAIN.C
void	generate_color(t_window *win, t_creature *creature);

//	WINDOW.C
int			init_display(t_window *win);
void		destroy_display(t_window *win);

//	SIM.C
void	ft_sim(t_window *win, t_sim *sim);

//	SIM_UTILS.C
void	draw_creature(t_window *win, t_sim *sim);
void	clear_creature(t_window *win, t_sim *sim);

//	MOVE.C
void		move_up(t_creature *c);
void		move_down(t_creature *c);
void		move_right(t_creature *c);
void		move_left(t_creature *c);
void		select_move(t_creature *c, int8_t m);

//	CREATURE.C
void		free_population(size_t nb_creat, t_creature **population);
void		check_creature_position(int *x, int *y, t_sim *sim);
t_creature	*init_creature(t_window *win, t_sim *sim);
t_creature	**create_new_creature(t_window *win, t_sim *sim);

//	FOOD.C
void	draw_food(t_window *win, t_sim *sim, t_food *t);
void	clear_food(t_window *win, t_sim *sim);
void	check_food_position(size_t *x, size_t *y, t_window *win, t_sim *sim);
t_food	*init_food(t_window *win, t_sim *sim);

//	SIGNAL.C
void	int_signal(int sig, siginfo_t *a, void *sim);
void	ft_signal(void);

#endif