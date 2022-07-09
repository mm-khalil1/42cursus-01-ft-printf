NAME = libftprintf.a

SRC = ft_putnbr_base.c		\
      	count_digits_u.c	\
     	count_digits_i.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar -rc $(NAME) $(OBJ)

clean:	make clean -C libft
	rm -f $(OBJ)

fclean: make fclean libft
	clean
	rm -f $(NAME)

re: fclean all

