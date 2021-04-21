/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:44:07 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/05 12:22:19 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/cub3D.h"

/******************************************************/
					/* FUNCTIONS */
/******************************************************/
 
// Render next frame loop
int			render_next_frame(t_params *mlx_params)
{
	mlx_params->img.img = mlx_new_image(mlx_params->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_params->img.addr = mlx_get_data_addr(mlx_params->img.img, &mlx_params->img.bits_per_pixel, &mlx_params->img.line_length, &mlx_params->img.endian);
	
	mlx_put_image_to_window(mlx_params->mlx, mlx_params->win, mlx_params->img.img, 0, 0);

	my_mlx_img_put(mlx_params, 10, 20);

	// draw_minimap(mlx_params);
	// draw_player(mlx_params, create_trgb(0, 0, 255, 255));

	draw_rays2D(mlx_params);

	eval_keys_status(mlx_params);

	return (0);
}
/******************************************************/
					/* MAIN */
/******************************************************/

int		main(void)
{	
	t_params 	mlx_params;
	void		*mlx_params_ptr;

	mlx_params_ptr = &mlx_params;

	params_init(&mlx_params);
	mlx_params.mlx = mlx_init();
	mlx_params.win = mlx_new_window(mlx_params.mlx, WIN_WIDTH, WIN_HEIGHT, "-- Rear Window --");

	mlx_loop_hook(mlx_params.mlx, render_next_frame, (void *)mlx_params_ptr);
	
	mlx_hook(mlx_params.win, X_EVENT_KEY_PRESS, 0, &button_down, &mlx_params); // track key press
	mlx_hook(mlx_params.win, X_EVENT_KEY_RELEASE, 0, &button_up, &mlx_params); // track key release
	mlx_hook(mlx_params.win, 17, 1L << 17, &ft_exit, &mlx_params); // exit when the red X is pressed

	mlx_loop(mlx_params.mlx);

	return (0);
}
