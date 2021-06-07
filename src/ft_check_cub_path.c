/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cub_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:58:59 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/05 12:59:00 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_end(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'b' || filename[len - 2] != 'u'
		|| filename[len - 3] != 'c' || filename[len - 4] != '.')
		return (-1);
	else
		return (1);
}

void	ft_check_cub_path(char *filename)
{
	char	*out_str;
	int		fd;

	out_str = ft_strjoin("Incorrect filepath regarding ", filename);
	fd = open(filename, O_RDONLY);
	if (fd <= 0 || (ft_check_end(filename) == -1))
	{
		ft_error(out_str);
		free(out_str);
		exit(0);
	}
	free(out_str);
}
