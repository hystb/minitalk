# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 17:43:21 by nmilan            #+#    #+#              #
#    Updated: 2023/01/17 14:08:31 by nmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CLIENT    =	src_client/main.c \
				src_client/utils.c
				
SRC_SERVER =	src_server/main.c \
				src_server/utils.c

INCLUDE_CLIENT =	src_client/client.h

INCLUDE_SERVER =	src_server/server.h 

OBJS_CLIENT    =    ${SRC_CLIENT:src_client/%.c=src_client/%.o}

OBJS_SERVER    =    ${SRC_SERVER:src_server/%.c=src_server/%.o}

NAME 		= minitalk

NAME_CLIENT = client

NAME_SERVER = server

CFLAGS    = -Wall -Wextra -Werror

FT_PRINTF_PATH	=	ft_printf/

FT_PRINTF_FILE	=	libftprintf.a

FT_PRINTF_LIB	=	$(addprefix $(FT_PRINTF_PATH), $(FT_PRINTF_FILE))

CC = cc

all : libs $(NAME)

libs :
			make -C $(FT_PRINTF_PATH)

$(NAME) : $(NAME_CLIENT) $(NAME_SERVER)

${NAME_CLIENT} : ${OBJS_CLIENT}
			$(CC) $(OBJS_CLIENT) -o $(NAME_CLIENT)

${NAME_SERVER} : $(FT_PRINTF_LIB) ${OBJS_SERVER}
			$(CC) $(OBJS_SERVER) $(FT_PRINTF_LIB) -o $(NAME_SERVER)
			
$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_PATH)

src_client/%.o: src_client/%.c    Makefile $(INCLUDE_CLIENT)
		${CC} ${CFLAGS} -I $(INCLUDE_CLIENT) -c $< -o $@

src_server/%.o: src_server/%.c    Makefile $(INCLUDE_SERVER)
		${CC} ${CFLAGS} -I $(INCLUDE_SERVER) -c $< -o $@

clean :
	make clean -C $(FT_PRINTF_PATH)
	rm -f $(OBJS_CLIENT)
	rm -f $(OBJS_SERVER)


fclean : clean
	make fclean -C $(FT_PRINTF_PATH)
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)


re : fclean
	make all

.PHONY:        all clean fclean re
