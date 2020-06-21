# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmustach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 19:44:11 by nmustach          #+#    #+#              #
#    Updated: 2020/06/22 03:41:52 by nmustach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

FLAGS = -Wall -Wextra -Werror

#PFTPATH = ../ft_printf/ -lftprintf

HEADERS = lem_in.h get_next_line.h

OBJDIR = objs

LFTPATH = ./libft -lft

SRC = main.c parse_input.c get_next_line.c ft_atoi_validate_pos.c hash.c debug_functions.c parse_functions.c

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo 'Linking... '
	@make -s -C $(LFTPATH)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LFTPATH)
	@echo 'DONE'

$(OBJDIR)/%.o : %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@
	@echo 'Compile $<'

clean:
		@echo 'rm object files..'
		@rm -f $(OBJ)
		@echo 'DONE'

fclean:
		@echo 'rm object files & executable..'
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@echo 'DONE'

re: fclean all