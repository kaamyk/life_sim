NAME = sim

SIMSRCS =	main.c	window.c	move.c	creature.c\

SIMOBJS =	$(SIMSRCS:.c=.o)

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror -g3

LIB		=	-lX11

all:		$(NAME)

$(NAME): 		$(SIMOBJS)
		$(CC) $(FLAGS) $(SIMOBJS) $(LIB) -o $(NAME)

clean:
		rm -f $(SIMOBJS)

fclean:			clean
		rm -f $(NAME)

re:				clean	fclean	all