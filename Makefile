# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmustach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 19:44:11 by nmustach          #+#    #+#              #
#    Updated: 2020/07/07 02:08:25 by nmustach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

#PFTPATH = ../ft_printf/ -lftprintf

HEADERS = lem_in.h

OBJDIR = objs/

CC = clang

OPFLAGS = -O2

LFTPATH = ./libft -lft

SRC = $(wildcard *.c)

LIBSRC = $(wildcard ./libft/*.c)

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))
 
all: $(NAME) 

$(NAME): $(OBJ) $(LIBSRC)
		@echo 'Linking $@... '
		@make -s -C $(LFTPATH)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(LFTPATH)
		@echo 'DONE'
		
		
include $(wildcard $(OBJDIR)*.d)  

$(OBJDIR)%.o : %.c
		@mkdir -p $(@D)
		@$(CC) -g -MMD $(FLAGS) -c $< -o $@
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
