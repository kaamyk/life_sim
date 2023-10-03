# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <antoine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 17:59:08 by anvincen          #+#    #+#              #
#    Updated: 2023/10/04 00:01:33 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lifesim

SRCDIR		=	sources

SRCS		=	$(wildcard $(SRCDIR)/*.cpp)

OBJDIR		=	obj

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
	@echo "Compiling " $<
	@sleep 0.1
	@clear
	@echo "Compiling " $< " ..."
	@$(CCPP) $(CFLAGS) $(CPPFLAGS) $(SFMLFLAGS) -c $< -o $@ 

$(NAME)			:	$(OBJS)
	@clear
	@echo -e '\033[0;34mObjects compilation : \x1b[32m>>> OK <<<\x1b[37m'
	@echo -e '\033[0;34mCompiling executable ...\x1b[37m'
	@clear
	@$(CCPP) $(VGFLAGS) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(SFMLFLAGS) -o $(NAME)

clean			:
	@echo -e '\033[0;34mremoving object files ...\x1b[37m'
	@rm -rf $(OBJDIR)
	@echo -e '\033[0;34mObject files are removed : \x1b[32m>>> OK <<<\x1b[37m'

fclean			:	clean
	@echo -e '\033[0;34mremoving executable files ...\x1b[37m'
	@rm -f $(NAME)
	@echo -e '\033[0;34mExecutable files are removed : \x1b[32m>>> OK <<<\x1b[37m'

re		: fclean	all
