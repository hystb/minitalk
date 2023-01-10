NAME = libftprintf.a

UTILS_FOLD = utils/

PROG = ft_printf.c\
switchman.c\

UTILS_PROG = $(addprefix $(UTILS_FOLD), ft_putchar_fd.c)\
$(addprefix $(UTILS_FOLD), ft_puthex_maj.c)\
$(addprefix $(UTILS_FOLD), ft_puthex_min.c)\
$(addprefix $(UTILS_FOLD), ft_puthex_ptr.c)\
$(addprefix $(UTILS_FOLD), ft_putnbr_fd.c)\
$(addprefix $(UTILS_FOLD), ft_putstr_fd.c)\
$(addprefix $(UTILS_FOLD), ft_strlen.c)\
$(addprefix $(UTILS_FOLD), ft_putnbr_unsigned.c)

OBJ = $(PROG:.c=.o)

UTILS_OBJ = $(UTILS_PROG:.c=.o)

CC = cc

FLAG = -Wall -Wextra -Werror

INCLUDE = ft_printf.h

all : $(NAME) 

clean : 
		rm -f $(OBJ)
		rm -f $(UTILS_OBJ)

fclean : clean
		rm -f $(NAME)

re: fclean 
	make all

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(FLAG) -c $< -o $@ -I $(INCLUDE)

$(UTILS_FOLD)%.o: $(UTILS_FOLD)%.c $(INCLUDE) Makefile
	$(CC) $(FLAG) -c $< -o $@ -I $(INCLUDE)

$(NAME) : $(PROG) $(OBJ) $(UTILS_PROG) $(UTILS_OBJ)
		ar rc $(NAME) $(OBJ) $(UTILS_OBJ)

.PHONY = all clean fclean re
