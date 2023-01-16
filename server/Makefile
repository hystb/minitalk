# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 17:46:46 by nmilan            #+#    #+#              #
#    Updated: 2023/01/16 17:48:02 by nmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC    =	main.c \
			utils.c \			

OBJS    =    ${SRC:%.c=%.o}

INCLUDE		=	server.h \

CC    = cc

NAME    = server

CFLAGS    = -Wall -Wextra -Werror

FT_PRINTF_PATH	=	ft_printf/

FT_PRINTF_FILE	=	libftprintf.a

FT_PRINTF_LIB	=	$(addprefix $(FT_PRINTF_PATH), $(FT_PRINTF_FILE))

all :        ${NAME}

lib_pf:
	make -C $(FT_PRINTF_PATH)

${NAME} : lib_pf ${OBJS} Makefile
			$(CC) $(OBJS) $(FT_PRINTF_LIB) -o $(NAME)
clean :
	make clean -C $(FT_PRINTF_PATH)
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)
	make fclean -C $(FT_PRINTF_PATH)


re :		fclean
			make all

%.o: %.c    Makefile $(INCLUDE)
		${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@


.PHONY:        all clean fclean re lib_pf
