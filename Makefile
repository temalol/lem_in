# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmustach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 19:44:11 by nmustach          #+#    #+#              #
#    Updated: 2020/06/28 01:33:37 by nmustach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

FLAGS = -Wall -Wextra -Werror

#PFTPATH = ../ft_printf/ -lftprintf

HEADERS = lem_in.h

OBJDIR = objs

CC = clang

OPFLAGS = -O2

LFTPATH = ./libft -lft

SRC = main.c parse_input.c ft_atoi_validate_pos.c hash.c debug_functions.c parse_functions.c gnl.c

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
 
all: $(NAME)

$(NAME): $(OBJ)
	@echo 'Linking... '
	@make -s -C $(LFTPATH)
	@$(CC) -g $(FLAGS) -o $(NAME) $(OBJ) -L $(LFTPATH)
	@echo 'DONE'

$(OBJDIR)/%.o : %.c $(HEADERS) Makefile
	@mkdir -p $(@D) 
	@$(CC) -g $(OPFLAGS) $(FLAGS) -c $< -o $@ 
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