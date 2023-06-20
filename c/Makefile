NAME = sim

SIMSRCS =	main.c	window.c	sim.c	sim_utils.c	creature.c	food.c move.c\
			signal.c\
			

SIMOBJS =	$(SIMSRCS:.c=.o)

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror -g3

LIB		=	-lX11

%.o:					%.c
		$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): 		$(SIMOBJS)
		$(CC) $(FLAGS) $(SIMOBJS) $(LIB) -o $(NAME)

clean:
		rm -f $(SIMOBJS)

fclean:			clean
		rm -f $(NAME)

re:				clean	fclean	all