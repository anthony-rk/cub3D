/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:53:48 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/14 09:54:15 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_raycast(t_params *p)
{
	t_raycast	r;
	t_raycast	*rc;
	float		wall_dist[800];

	rc = &r;
	init_rc_struct(p, rc);
	while (rc->r < p->win_width)
	{
		get_horiz_line_dist(p, rc);
		get_vert_line_dist(p, rc);
		set_ray_vars_to_shorter(p, rc);
		wall_dist[rc->r] = rc->disT;
		set_line_and_texture_vars(p, rc);
		ft_draw_walls(p, rc);
		rc->ra += (DR) / (p->win_width / 60);
		rc->ra = fix_angle_rad(rc->ra);
		rc->r += 1;
	}
	if (rc->has_sprite == 1)
		draw_sprites(p, wall_dist);
}
