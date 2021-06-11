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

SRCS =	./check_buttons.c \
		./color_functions.c \
		./cub_reader.c \
		./draw_lines.c \
		./draw_minimap.c \
		./draw_shapes.c \
		./fix_angles.c \
		./ft_analyze_map_line.c \
		./ft_check_cub_path.c \
		./ft_check_cub_vars_utils.c \
		./ft_check_cub_vars.c \
		./ft_check_filepaths.c \
		./ft_draw_sprites_utils.c \
		./ft_draw_sprites.c \
		./ft_draw_walls.c \
		./ft_error.c \
		./ft_exit.c \
		./ft_handle_res.c \
		./ft_map_reader_utils.c \
		./ft_map_reader.c \
		./ft_parse_map.c \
		./ft_raycast_utils.c \
		./ft_raycast.c \
		./ft_verify_map_utils.c \
		./ft_verify_map.c \
		./get_horiz_line_dist.c \
		./get_vert_line_dist.c \
		./init_textures_utils.c \
		./init_textures.c \
		./main.c \
		./my_mlx_functions.c \
		./new_sprite.c \
		./params_init.c \
		./parse_cub_utils.c \
		./parse_cub.c \
		./rad_to_degree.c \
		./sort_sprites.c \
		./sprite_utils.c \
		./update_player_pos_utils.c \
		./update_player_pos.c \

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
