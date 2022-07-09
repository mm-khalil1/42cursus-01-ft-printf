NAME = libftprintf.a

SRC = ft_putnbr_base.c		\
      	count_digits.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar -rc $(NAME) $(OBJ)

clean:	
	rm -f $(OBJ)
	make clean -C libft
	
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	
re: fclean all

