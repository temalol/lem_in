# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmustach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 19:44:11 by nmustach          #+#    #+#              #
#    Updated: 2020/06/19 00:49:00 by nmustach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

FLAGS = -Wall -Wextra -Werror

#PFTPATH = ../ft_printf/ -lftprintf

LFTPATH = ./libft -lft

SRC = main.c parse_input.c get_next_line.c ft_atoi_validate_pos.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo 'Linking... '
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LFTPATH)
	@echo 'DONE'

%.o : %.c lem_in.h
	@gcc $(FLAGS) -c $< -o $@
	@echo 'Compile $<'

clean:
		@echo 'rm checker object files..'
		@rm -f $(OBJ)
		@echo 'DONE'

fclean:
		@echo 'rm checker object files & executable..'
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@echo 'DONE'

re: fclean all