# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/16 22:12:21 by vinda-si          #+#    #+#              #
#    Updated: 2026/07/16 22:45:24 by vinda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	intern
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC			=	main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp
OBJ			=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)
			rm -f *_shrubbery

re:		fclean all

.PHONY:	all clean fclean re
