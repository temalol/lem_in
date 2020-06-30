# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmustach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 16:38:23 by nmustach          #+#    #+#              #
#    Updated: 2020/06/29 04:54:16 by nmustach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
      ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
      ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
      ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
      ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
      ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
      ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
      ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
      ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
      ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
      ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
      ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
HEAD = ./
BIN = $(SRCS:.c=.o)  



CFLAGS = -Wall -Wextra -Werror -MD
CC = clang


all: $(NAME)

$(NAME): $(BIN)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)
     
     
#%.o : %.c Makefile \
#	$(CC) $(CFLAGS) -MD -c $< -o $@
	  
clean:
	rm -f $(BIN)

fclean: clean 
	rm -f $(NAME) 

re: fclean all
