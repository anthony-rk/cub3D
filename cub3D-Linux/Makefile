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

SRCS =	./src/check_buttons.c \
		./src/color_functions.c \
		./src/cub_reader.c \
		./src/draw_lines.c \
		./src/draw_minimap.c \
		./src/draw_shapes.c \
		./src/fix_angles.c \
		./src/ft_analyze_map_line.c \
		./src/ft_check_cub_path.c \
		./src/ft_check_cub_vars_utils.c \
		./src/ft_check_cub_vars.c \
		./src/ft_check_filepaths.c \
		./src/ft_draw_sprites_utils.c \
		./src/ft_draw_sprites.c \
		./src/ft_draw_walls.c \
		./src/ft_error.c \
		./src/ft_exit.c \
		./src/ft_hanlde_res.c \
		./src/ft_map_reader_utils.c \
		./src/ft_map_reader.c \
		./src/ft_parse_map.c \
		./src/ft_raycast_utils.c \
		./src/ft_raycast.c \
		./src/ft_verify_map_utils.c \
		./src/ft_verify_map.c \
		./src/get_horiz_line_dist.c \
		./src/get_vert_line_dist.c \
		./src/init_textures_utils.c \
		./src/init_textures.c \
		./src/main.c \
		./src/my_mlx_functions.c \
		./src/new_sprite.c \
		./src/params_init.c \
		./src/parse_cub_utils.c \
		./src/parse_cub.c \
		./src/rad_to_degree.c \
		./src/sort_sprite.c \
		./src/sprite_utils.c \
		./src/update_player_pos_utils.c \
		./src/update_player_pos.c \

OBJECTS = $(SRCS:.c=.o)

MLX_DIR = ./minilibx_linux
MLX_LIB = libmlx.a

all: $(NAME)

$(NAME):
	#############################
	#--   BUILD THE libft.a   --#
	#############################
	make re -C ./src/libft
	cp ./src/libft/libft.a .

	##################################
	#--   BUILD THE libmlx.a       --#
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
	gcc -Wall -Wextra -Werror ${OBJECTS} -L. -lmlx -L. -lft -lm -lX11 -lXext -o ${NAME}
clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C ./src/libft
	@make clean -C $(MLX_DIR)

fclean: clean
	@/bin/rm -f $(NAME) libft.a libmlx.a $(MLX_LIB)
	@/bin/rm -f $(OBJECTS)
	@make fclean -C ./src/libft

re: fclean all

.PHONY:	all clean fclean re

f:
	@make
	@./cub3D ./maps/map_5.cub
