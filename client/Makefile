# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 17:44:02 by nmilan            #+#    #+#              #
#    Updated: 2023/01/16 18:24:21 by nmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC    =	main.c \
			utils.c

OBJS    =    ${SRC:%.c=%.o}

CC    = cc

INCLUDE		=	client.h 

NAME    = client

CFLAGS    = -Wall -Wextra -Werror

all :        ${NAME}


${NAME} : ${OBJS} Makefile
			$(CC) $(OBJS) -o $(NAME)
clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re :		fclean
			make all

%.o: %.c    Makefile $(INCLUDE)
		${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o $@


.PHONY:        all clean fclean re
