/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_map_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:08:45 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/27 15:08:48 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_reader_error(t_params *params, int fd)
{
	close(fd);
	ft_error("GNL Reader returned -1");
	free(params->map);
	printf("Goodbye...\n");
	exit(0);
}

void	ft_analyze_map_line(t_params *params, char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (ft_strrchr(line, 'R') == 0 && ft_strrchr(line, 'O') == 0
		&& ft_strrchr(line, 'E') == 0 && ft_strrchr(line, 'F') == 0
		&& ft_strrchr(line, 'C') == 0
		&& (ft_strrchr(line, 'S') && ft_strrchr(line, '/')))
		return ;
	else if (ft_is_empty_line(line) == 1)
		return ;
	else
	{
		if (ft_is_valid_map_line(line) == 1)
			ft_store_map_line(params, line);
	}
}
