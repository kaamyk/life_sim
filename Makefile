# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <antoine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 17:59:08 by anvincen          #+#    #+#              #
#    Updated: 2023/09/27 22:45:56 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lifesim

SRCS		=	main.cpp	Fixed.cpp	Simulation.cpp	Creature.cpp

OBJS		=	$(SRCS:.cpp=.o)

CCPP		=	c++

CFLAGS		=	-Wall -Wextra -Werror

SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

VGFLAGS		=	-g

all		:	$(OBJS) $(NAME)

%.o		:	%.c
	@$(CCPP) $(CFLAGS) $(CPPFLAGS) $(SFMLFLAGS) -c $< -o $@ 

$(NAME)	:	$(OBJS)
	@echo -e '\033[0;34mObjects compilation : \x1b[32m>>> OK <<<\x1b[37m'
	@echo -e '\033[0;34mCompiling executable ...\x1b[37m'
	@$(CCPP) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(SFMLFLAGS) -o $(NAME)
	@echo -e '\033[0;34mExecutable compilation : \x1b[32m>>> OK <<<\x1b[37m'
	@sleep 0.5
	@clear

clean	:
	@echo -e '\033[0;34mremoving object files ...\x1b[37m'
	@rm -f $(OBJS)
	@echo -e '\033[0;34mObject files are removed : \x1b[32m>>> OK <<<\x1b[37m'

fclean	:	clean
	@echo -e '\033[0;34mremoving executable files ...\x1b[37m'
	@rm -f $(NAME)
	@echo -e '\033[0;34mExecutable files are removed : \x1b[32m>>> OK <<<\x1b[37m'

re		: fclean	all
