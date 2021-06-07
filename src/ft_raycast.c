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

void	ft_raycast(t_params *params)
{
	init_textures(params);

	float wall_dist[params->win_width]; // array to store dist to all walls at every raycast

	int r; // one ray
	int mx; // map array x location
	int my; // map array y location
	int dof; // depth of field, max is 8 as the map is 8 blocks wide & 8 blocks tall ORIGINALLY

	float rx; // ray x
	float ry; // ray y
	float ra; // ray angle, can replace with params->p_angle
	float xo; // x offset
	float yo; // y offset
	float disT;

	int has_sprite;
	has_sprite = 0;

	ra = params->player.p_angle - DR * 30; // set ray's angle to players angle - 30 Degrees in Radians
	ra = fix_angle_rad(ra);

	for (r = 0; r < params->win_width; r++) // Loop to do each raycast
	{
		// ---Check Horizontal Lines---
		dof = 0;
		float disH = 100000000;
		float hx = params->player.x;
		float hy = params->player.y;
		float aTan = -1 / tan(ra);

		if (ra > PI) // Looking Up
		{
			ry = round((((int)params->player.y >> 6) << 6)) - 0.0001; // Here, we chose to make ry part of the block above the line, that is why we subtract some from ry so that 191/64 = 2
			rx = (params->player.y - ry) * aTan + params->player.x;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI) // Looking Down
		{	
			ry = (((int)params->player.y >> 6) << 6) + 64; // Set the ry to whatever VERTICAL block we are in ie 64, 128, 192, 256, .. 512 
			rx = (params->player.y - ry) * aTan + params->player.x;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI) // Looking straight left or right
		{	
			rx = params->player.x;
			ry = params->player.y;
			dof = 100000000;
		}
		while (dof < params->map_xblocks || dof < params->map_yblocks)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			if (mx >= 0 && my >= 0 && mx < params->map_xblocks && my < params->map_yblocks && (params->map[my][mx] == '2'))
			{
				has_sprite = 1;
			}
			if (mx >= 0 && my >= 0 && mx < params->map_xblocks && my < params->map_yblocks && (params->map[my][mx] == '1'))
			{
				hx = rx;
				hy = ry;
				disH = dist(params->player.x, params->player.y, hx, hy);
				dof = 100000000; // hit a wall
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}

		// ---Check Vertical Lines---
		dof = 0;
		float disV = 100000000;
		float vx = params->player.x;
		float vy = params->player.y;
		float nTan = -tan(ra);

		if (ra > PI2 && ra < PI3) // Looking Left
		{
			rx = round((((int)params->player.x >> 6) << 6)) - 0.0001;
			ry = (params->player.x - rx) * nTan + params->player.y;
			xo = -64;
			yo = -xo * nTan;
		}
		if (ra < PI2 || ra > PI3) // Looking Right
		{
			rx = (((int)params->player.x >> 6) << 6) + 64;
			ry = (params->player.x - rx) * nTan + params->player.y;
			xo = 64;
			yo = -xo * nTan;
		}
		if (ra == PI3 || ra == PI2) // Looking straight up or down
		{
			rx = params->player.x;
			ry = params->player.y;
			dof = 100000;
		}
		while (dof < params->map_xblocks || dof < params->map_yblocks)
		{
			mx = (int)(rx) >> 6; // Basically like dividing by 64
			my = (int)(ry) >> 6;
			if (mx >= 0 && my >= 0 && mx < params->map_xblocks && my < params->map_yblocks && (params->map[my][mx] == '2'))
			{
				has_sprite = 1;
			}
			if (mx >= 0 && my >= 0 && mx < params->map_xblocks && my < params->map_yblocks && (params->map[my][mx] == '1'))
			{
				vx = rx;
				vy = ry;
				disV = dist(params->player.x, params->player.y, vx, vy);
				dof = 100000000; // hit a wall
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		
		float shade;
		shade = 1.0;

		// Draw the shorter ray in 2D grid
		if (disV < disH)
		{
			rx = vx;
			ry = vy;
			disT = disV;
			// draw_ab_line(params, ra, params->player.x, params->player.y, disV, create_trgb(0, 190, 0, 190)); // PURPLE
		}
		else // if (disH < disV)
		{
			shade = 0.5;
			rx = hx;
			ry = hy;
			disT = disH;
			// draw_ab_line(params, ra, params->player.x / 4, params->player.y / 4, disH / 4, create_trgb(0, 150, 0, 150)); // LIGHT PURPLE
		}


		// ---Draw 3D Wall-- // 
		float ca = params->player.p_angle - ra; // Fix Fisheye
		ca = fix_angle_rad(ca);
		disT = disT * cos(ca);

		// if (r == 30)
		// 	printf("%f\n", disT);

		// Add wall dist to the wall_dist array
		wall_dist[r] = disT;
		
		float lineH = (params->block_size * params->win_height) / disT; // Line height
		float ty_step = 63.99 / (float)lineH; // the amount to move in the texture array for each new iteration
		float ty_off = 0; // ty_offset
		
		if (lineH > params->win_height)
		{
			ty_off = ((lineH - params->win_height) / 2.0);
			lineH = params->win_height;
		}
		
		float lineOffset = params->win_height / 2 - lineH / 2;
		// float lineOffset = params->win_height / 2 - lineH; // I am on the floor, like crouching here

		int y; // increment y for each pixel
		int color; // Texture Color

		float ty; // TEXTURE Y
		float tx; // TEXTURE X

		ty = (ty_off * ty_step); // the index to which to grab the color from the texture array

		// Get the texture x value
		if (shade == 0.5) // up | down
		{
			tx = (int)(rx) % 64;
			if (ra < PI) // LOOKING DOWN, SO FLIP THE TEXTURE
				tx = 63 - tx;
		}
		else
		{
			tx = (int)(ry) % 64;
			if (ra >= PI2 && ra <= PI3) // LOOKING lEFT, SO FLIP THE TEXTURE
				tx = 63 - tx;
		}

		y = 0;
		if (disH < disV)
		{
			while (y < lineH)
			{
				// Need to check the angle to determine is N,E,S,W wall texture should be displayed
				if (ra < PI)
				{
					color = params->n_wall_texture.addr[((int)(ty)) * 64 + (int)(tx)];
				}
				else
				{
					color = params->s_wall_texture.addr[((int)(ty)) * 64 + (int)(tx)];
				}

				draw_horiz_line(params, r, lineOffset + y, 1, color);
				ty += ty_step;
				y++;
			}
			draw_3d_vert_line(params, r, lineOffset + lineH, params->win_height - (lineH + lineOffset),  params->floor_color, 1); // Draw Floors
			draw_3d_vert_line(params, r, 0, lineOffset,  params->ceil_color, 1); // Draw Ceiling
		}
		else
		{
			while (y < lineH) // draw the line height based off the image
			{
				if (ra >= PI2 && ra <= PI3)
				{
					color = params->e_wall_texture.addr[((int)(ty)) * 64 + (int)(tx)];
				}
				else
				{
					color = params->w_wall_texture.addr[((int)(ty)) * 64 + (int)(tx)];
				}
				draw_horiz_line(params, r, lineOffset + y, 1, color);
				ty += ty_step;
				y++;
			}
			draw_3d_vert_line(params, r, lineOffset + lineH, params->win_height - (lineH + lineOffset),  params->floor_color, 1); // Draw Floors
			draw_3d_vert_line(params, r, 0, lineOffset,  params->ceil_color, 1); // Draw Ceiling
		}
		// Increment the Ray Angle
		ra += (DR) / (params->win_width / 60);
		ra = fix_angle_rad(ra);

		// if (r == 30)
		// 	printf("ra: %f\n", ra);
	}
	// Draw Sprite after walls were drawn
	if (has_sprite == 1)
		draw_sprites(params, wall_dist);
}