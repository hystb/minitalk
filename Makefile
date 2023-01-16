# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 17:43:21 by nmilan            #+#    #+#              #
#    Updated: 2023/01/16 17:54:20 by nmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_PATH = server

CLIENT_PATH = client

all : Makefile
	make -C $(SERVER_PATH)
	make -C $(CLIENT_PATH)

clean :
	make clean -C $(SERVER_PATH)
	make clean -C $(CLIENT_PATH)

fclean : clean

re : fclean
	make all

.PHONY:        all clean fclean re
