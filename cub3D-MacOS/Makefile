# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 15:57:17 by akowalsk          #+#    #+#              #
#    Updated: 2021/06/07 09:14:55 by akowalsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	./src/*.c

OBJECTS = ./*.o

MLX_DIR = ./minilibx
MLX_LIB = libmlx.dylib

all: $(NAME)

$(NAME):
	#############################
	#--   BUILD THE libft.a   --#
	#############################
	make re -C ./src/libft
	cp ./src/libft/libft.a .

	##################################
	#--   BUILD THE libmlx.dylib   --#
	##################################
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX_LIB) .
	
	########################
	#--   MAKE .o FILE   --#
	########################
	gcc -Wall -Wextra -Werror -c $(SRCS)

	########################################
	#--   MAKE ./cub3D EXECUTABLE FILE   --#
	########################################
	gcc -Wall -Wextra -Werror -o $(NAME) -L. -lmlx -L. -lft $(OBJECTS) -framework OpenGL -framework AppKit

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C ./src/libft
	@make clean -C $(MLX_DIR)

fclean: clean
	@/bin/rm -f $(NAME) libft.a $(MLX_LIB)
	@/bin/rm -f $(OBJECTS)
	@make fclean -C ./src/libft

re: fclean all

.PHONY:	all clean fclean re

f:
	@make
	@./cub3D ./maps/map_10.cub

