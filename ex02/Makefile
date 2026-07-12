# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/17 20:25:03 by vinda-si          #+#    #+#              #
#    Updated: 2026/05/17 20:40:31 by vinda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	forms
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC			=	main.c \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp
OBJ			=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f *_shrubbery

re:	fclean all

.PHONY:	all clean fclean re
