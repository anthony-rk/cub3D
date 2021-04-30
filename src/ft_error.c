/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 09:36:02 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/16 09:36:17 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	ft_error(t_params *params, char *err_message)
void	ft_error(char *err_message)
{
	printf("Error\n%s\n", err_message);
	// ft_exit(params);
}