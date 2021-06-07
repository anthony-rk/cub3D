# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 15:57:17 by akowalsk          #+#    #+#              #
#    Updated: 2021/05/27 10:08:01 by akowalsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	./src/*.c

OBJECTS = ./*.o

all: $(NAME)

$(NAME):
	# build the libft.a 
	make re -C ./src/libft
	cp ./src/libft/libft.a .

	# Need to make .o files for all my cub3D Files
	gcc -Wall -Wextra -Werror -c $(SRCS)

	gcc -Wall -Wextra -Werror -o ${NAME} -L. -lmlx -L. -lft ${OBJECTS} -framework OpenGL -framework AppKit

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C ./src/libft

fclean: clean
	@/bin/rm -f $(NAME) libft.a
	@/bin/rm -f $(OBJECTS)
	@make fclean -C ./src/libft

re: fclean all

.PHONY:	all clean fclean re

f:
	@make
	@./cub3D ./maps/map_4.cub
