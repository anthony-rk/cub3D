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
		./src/ft_handle_res.c \
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
		./src/sort_sprites.c \
		./src/sprite_utils.c \
		./src/update_player_pos_utils.c \
		./src/update_player_pos.c

OBJECTS =	./check_buttons.o \
			./color_functions.o \
			./cub_reader.o \
			./draw_lines.o \
			./draw_minimap.o \
			./draw_shapes.o \
			./fix_angles.o \
			./ft_analyze_map_line.o \
			./ft_check_cub_path.o \
			./ft_check_cub_vars_utils.o \
			./ft_check_cub_vars.o \
			./ft_check_filepaths.o \
			./ft_draw_sprites_utils.o \
			./ft_draw_sprites.o \
			./ft_draw_walls.o \
			./ft_error.o \
			./ft_exit.o \
			./ft_handle_res.o \
			./ft_map_reader_utils.o \
			./ft_map_reader.o \
			./ft_parse_map.o \
			./ft_raycast_utils.o \
			./ft_raycast.o \
			./ft_verify_map_utils.o \
			./ft_verify_map.o \
			./get_horiz_line_dist.o \
			./get_vert_line_dist.o \
			./init_textures_utils.o \
			./init_textures.o \
			./main.o \
			./my_mlx_functions.o \
			./new_sprite.o \
			./params_init.o \
			./parse_cub_utils.o \
			./parse_cub.o \
			./rad_to_degree.o \
			./sort_sprites.o \
			./sprite_utils.o \
			./update_player_pos_utils.o \
			./update_player_pos.o

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
	@/bin/rm -f $(NAME) $(MLX_LIB)
	@/bin/rm -f $(OBJECTS)
	@make fclean -C ./src/libft

re: fclean all

bonus: fclean all

.PHONY:	all clean fclean re bonus

f:
	@make
	@./cub3D ./maps/map_10.cub
