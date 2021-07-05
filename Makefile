NAME = libftprintf.a

SRC = ft_printf.c get_flags.c get_star.c print_charstr.c \
		  print_percent.c print_pointer.c print_interger.c print_uhex.c \
		  utils.c utils_a.c utils_extra.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ft_printf.h

all: $(NAME)
	
$(NAME): $(INCLUDES)
	@gcc $(CFLAGS) -c $(SRC)
#	@gcc $(OBJ)
#	@./a.out
	ar rc $(NAME) $(OBJ)

git:	fclean
		git add .
		git commit -m "newcommit"
		git push

clean:
		rm -f $(OBJ) a.out

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
