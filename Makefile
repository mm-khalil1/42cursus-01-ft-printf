# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 18:48:23 by mkhalil           #+#    #+#              #
#    Updated: 2022/07/09 18:48:23 by mkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_putnbr_base.c		\
      	ft_printf_utils1.c		\
		ft_printf_utils2.c		\
		ft_printf.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	mv libft/libft.a $(NAME)
	ar -rc $(NAME) $(OBJ)

clean:	
	rm -f $(OBJ)
	make clean -C libft
	
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	
re: fclean all

