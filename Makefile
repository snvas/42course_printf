NAME = libftprintf.a

SRCFILES = ft_printf.c\
	  get_flags.c\
	  get_star.c\
	  print_charstr.c\
	  print_percent.c\
	  print_pointer.c\
	  print_interger.c\
	  print_uhex.c\
	  utils.c\
	  utils_a.c
BONUSFILES = ft_printf_bonus.c\
		   get_flags_bonus.c\
		   get_star_bonus.c\
		   print_charstr_bonus.c\
		   print_percent_bonus.c\
		   print_pointer_bonus.c\
		   print_interger_bonus.c\
		   print_uhex_bonus.c\
		   utils_bonus.c\
		   utils_a_bonus.c
SRCDIR = ./src
BONUSDIR = ./bonus
SRC = $(addprefix $(SRCDIR)/, $(SRCFILES))
SRCBONUS = $(addprefix $(BONUSDIR)/, $(BONUSFILES))

OBJFILES = $(SRCFILES:.c=.o)
OBJBONUSFILES = $(BONUSFILES:.c=.o)
OBJ =  $(addprefix ./obj/, $(OBJFILES))
OBJBONUS = $(addprefix ./obj/, $(OBJBONUSFILES))
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = ./src/ft_printf.h
INCLUDESBONUS = ./bonus/ft_printf_bonus.h
all: $(NAME)

./obj/%.o: ./src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) $< -c -o $@

./obj/%.o: ./bonus/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME): $(INCLUDES) $(OBJ)
#	@gcc $(OBJ)
#	@./a.out
	ar rc $(NAME) $(OBJ)

bonus: $(INCLUDESBONUS) $(OBJBONUS)
	ar rc $(NAME) $(OBJBONUS)

git:	fclean
		git add .
		git commit -m "newcommit"
		git push

clean:
		rm -f $(OBJ) a.out
		rm -f $(OBJBONUS) a.out
		rm -rf obj

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
