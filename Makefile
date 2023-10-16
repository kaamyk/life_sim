# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <antoine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 17:59:08 by anvincen          #+#    #+#              #
#    Updated: 2023/10/05 21:51:44 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lifesim

SRCDIR		=	sources

SRCS		=	$(wildcard $(SRCDIR)/*.cpp)

OBJDIR		=	.obj

OBJS		=	$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

CCPP		=	c++

CFLAGS		=	-Wall -Wextra -Werror

SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

VGFLAGS		=	-g

all				:	$(OBJDIR) $(OBJS) $(NAME)

$(OBJDIR)		:
	mkdir $(OBJDIR)

$(OBJDIR)/%.o	:	$(SRCDIR)/%.cpp
	@clear
	@echo "Compiling " $< " ..."
	@$(CCPP) $(CFLAGS) $(CPPFLAGS) $(SFMLFLAGS) -c $< -o $@ 
	@clear
	@echo -e 'Compiling ' $< ' \x1b[32m>>> OK <<<\x1b[37m'
	@sleep 0.5

$(NAME)			:	$(OBJS)
	@clear
	@echo -e '\033[0;34mObjects compilation : \x1b[32m>>> OK <<<\x1b[37m'
	@echo -e '\033[0;34mCompiling executable ...\x1b[37m'
	@clear
	@$(CCPP) $(VGFLAGS) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(SFMLFLAGS) -o $(NAME)

clean			:
	@echo -e '\033[0;34mRemoving object files ...\x1b[37m'
	@rm -rf $(OBJDIR)
	@clear
	@echo -e '\033[0;34mRemoving object files \x1b[32m>>> OK <<<\x1b[37m'

fclean			:	clean
	@echo -e '\033[0;34mRemoving executable files ...\x1b[37m'
	@rm -f $(NAME)
	clear
	@echo -e '\033[0;34mRemoving executable files \x1b[32m>>> OK <<<\x1b[37m'
	@sleep 1
	@clear

re		: fclean	all
