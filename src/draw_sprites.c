/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:06:19 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/26 19:06:20 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Need to break this function up, but too many variables...
static void 	put_sprite(t_params *params, int sprite, float *wall_dist)
{
	float lineH = (64 * params->win_height) / params->sprites[sprite]->dist; // Line height
	float lineW = lineH; // Do not need to crop this one
	float ty_step = 63.9 / (float)lineH; // the amount to move in the texture array for each new iteration
	float ty_off = 0; // ty_offset
	
	if (lineH > params->win_height)
	{
		ty_off = ((lineH - params->win_height) / 2.0);
		lineH = params->win_height;
	}
	
	float lineOffset = params->win_height / 2 - lineH / 2;
	int color;	  // Texture Color
	float ty;	  // TEXTURE Y
	float tx; 	  // TEXTURE X

	ty = (ty_off * ty_step);
	tx = 0;
	if (params->sprites[sprite]->screenx > params->win_width / 2) // right
	{
		for (int x = 0; x < lineW; x++)
		{
			ty = 0;
			for (int y = 0; y < lineH; y++)
			{
				color = params->sprite_texture.addr[((int)(ty)) * 64 + (int)(tx)];
				if (color != 0 && params->sprites[sprite]->screenx - lineW / 2 + x < params->win_width && params->sprites[sprite]->dist < wall_dist[(int)(params->sprites[sprite]->screenx - lineW / 2 + x)])
					draw_horiz_line(params, params->sprites[sprite]->screenx - lineW / 2 + x, lineOffset + y, 1, color);
				ty += ty_step;
			}
			tx += ty_step;
		}
	}
	else
	{
		for (int x = lineW; x > 0; x--)
		{
			ty = 0;
			for (int y = 0; y < lineH; y++)
			{
				color = params->sprite_texture.addr[((int)(ty)) * 64 + (int)(tx)];
				if (color != 0 && params->sprites[sprite]->screenx + lineW / 2 - x > 0 && params->sprites[sprite]->dist < wall_dist[(int)(params->sprites[sprite]->screenx + lineW / 2 - x)])
					draw_horiz_line(params, params->sprites[sprite]->screenx + lineW / 2 - x, lineOffset + y, 1, color);
				ty += ty_step;
			}
			tx += ty_step;
		}
	}
}

static void 	update_sprite_data(t_params *params, int num_sprites)
{
	int		i;
	double	left_p_angle;
	double	q;

	i = -1;
	while (++i < num_sprites)
	{
		get_sprite_dist(params, params->sprites[i]);

		left_p_angle = 360 - rad_to_degree(params->player.p_angle - (DR * 60 / 2));
		left_p_angle = fix_angle(left_p_angle);
		q = left_p_angle - (params->sprites[i]->ang);

		if ((rad_to_degree(params->player.p_angle)) < 90 && (params->sprites[i]->ang > 270) && q < 0) // player in quadrant 1 for p_angle and quadrant 4 for sprite angle
			q += 360;
		if ((rad_to_degree(params->player.p_angle)) > 270 && (params->sprites[i]->ang) < 90 && q > 360) // player in quadrant 4 for p_angle and quadrant 1 for sprite angle
			q -= 360;
		params->sprites[i]->screenx = q * (params->win_width / 60);
		params->sprites[i]->screeny = (params->win_height / 2);
	}
}

void			draw_sprites(t_params *params, float *wall_dist)
{
	int 	num_sprites;
	int		i;

	num_sprites = params->num_sprites;

	update_sprite_data(params, num_sprites);
	sort_sprites(params, num_sprites);

	i = -1;
	while (++i < num_sprites)
		put_sprite(params, i, wall_dist);
}
