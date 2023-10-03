# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <antoine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 17:59:08 by anvincen          #+#    #+#              #
#    Updated: 2023/10/03 22:00:29 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lifesim

SRCS		=	main.cpp	Fixed.cpp	Simulation.cpp	Creature.cpp	\
				assetManager.cpp

OBJS		=	$(SRCS:.cpp=.o)

CCPP		=	c++

CFLAGS		=	-Wall -Wextra -Werror

SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

VGFLAGS		=	-g

all		:	$(OBJS) $(NAME)

%.o		:	%.cpp
	@clear
	@echo "Compiling " $<
	@sleep 0.1
	@clear
	@echo "Compiling " $< " ..."
	@$(CCPP) $(CFLAGS) $(CPPFLAGS) $(SFMLFLAGS) -c $< -o $@ 

$(NAME)	:	$(OBJS)
	@clear
	@echo -e '\033[0;34mObjects compilation : \x1b[32m>>> OK <<<\x1b[37m'
	@echo -e '\033[0;34mCompiling executable ...\x1b[37m'
	@sleep 1
	@clear
	@$(CCPP) $(VGFLAGS) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(SFMLFLAGS) -o $(NAME)

clean	:
	@echo -e '\033[0;34mremoving object files ...\x1b[37m'
	@echo -e '\033[0;34mObject files are removed : \x1b[32m>>> OK <<<\x1b[37m'
	@rm -f $(OBJS)

fclean	:	clean
	@echo -e '\033[0;34mremoving executable files ...\x1b[37m'
	@echo -e '\033[0;34mExecutable files are removed : \x1b[32m>>> OK <<<\x1b[37m'
	@rm -f $(NAME)

re		: fclean	all
