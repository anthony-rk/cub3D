/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:30:09 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/16 20:30:12 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len;
	unsigned int	i;
	const void		*ptr;

	if (!s)
		return ;
	ptr = s;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		write(fd, &ptr[i], 1);
		i++;
	}
}
