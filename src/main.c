/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:44:07 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/27 10:55:10 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/******************************************************/
					/* RENDER FUNCTION */
/******************************************************/

static int	render_next_frame(t_params *p)
{
	t_img	*i;

	i = &p->img;
	i->img = mlx_new_image(p->mlx, p->win_width, p->win_height);
	i->addr = (int *)mlx_get_data_addr(i->img, &i->bits_per_pixel, \
		&i->line_length, &i->endian);
	mlx_put_image_to_window(p->mlx, p->win, i->img, 0, 0);
	ft_raycast(p);
	if (p->m == 1)
		draw_minimap(p);
	update_player_pos(p);
	return (0);
}

/******************************************************/
					/* MAIN */
/******************************************************/

int	main(int argc, char *argv[])
{
	t_params	mlx_p;
	void		*mlx_p_ptr;

	if (argc == 2)
	{
		ft_check_cub_path(argv[1]);
		mlx_p_ptr = &mlx_p;
		params_init(&mlx_p);
		mlx_p.mlx = mlx_init();
		cub_reader(&mlx_p, argv[1]);
		mlx_p.win = mlx_new_window(mlx_p.mlx, \
			mlx_p.win_width, mlx_p.win_height, "-- Cub3D --");
		mlx_loop_hook(mlx_p.mlx, render_next_frame, (void *)mlx_p_ptr);
		mlx_hook(mlx_p.win, X_EVENT_KEY_PRESS, 0, &button_down, &mlx_p);
		mlx_hook(mlx_p.win, X_EVENT_KEY_RELEASE, 0, &button_up, &mlx_p);
		mlx_hook(mlx_p.win, 17, 1L << 17, &ft_exit, &mlx_p);
		mlx_loop(mlx_p.mlx);
	}
	else
		ft_error("Execution should be: \"./cub3D example.cub\"");
	return (0);
}
