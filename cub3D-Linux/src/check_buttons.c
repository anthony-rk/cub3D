/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buttons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:09:44 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/06 12:09:53 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	button_down(int keycode, t_params *params)
{
	if (keycode == KEY_A)
		params->a = 1;
	if (keycode == KEY_D)
		params->d = 1;
	if (keycode == KEY_S)
		params->s = 1;
	if (keycode == KEY_W)
		params->w = 1;
	if (keycode == KEY_LARROW)
		params->left_arrow = 1;
	if (keycode == KEY_RARROW)
		params->right_arrow = 1;
	if (keycode == KEY_ESC)
		params->esc = 1;
	if (keycode == KEY_M)
		params->m *= -1;
	return (0);
}

int	button_up(int keycode, t_params *params)
{
	if (keycode == KEY_A)
		params->a = 0;
	if (keycode == KEY_D)
		params->d = 0;
	if (keycode == KEY_S)
		params->s = 0;
	if (keycode == KEY_W)
		params->w = 0;
	if (keycode == KEY_LARROW)
		params->left_arrow = 0;
	if (keycode == KEY_RARROW)
		params->right_arrow = 0;
	return (0);
}
