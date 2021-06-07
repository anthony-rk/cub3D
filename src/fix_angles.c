/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_angles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:56:07 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/03 14:56:08 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	fix_angle(double ang)
{
	if (ang < 0)
		ang += 360;
	if (ang > 360)
		ang -= 360;
	return (ang);
}

double	fix_angle_rad(double ang)
{
	if (ang < 0)
		ang += 2 * M_PI;
	if (ang > 2 * M_PI)
		ang -= 2 * M_PI;
	return (ang);
}
