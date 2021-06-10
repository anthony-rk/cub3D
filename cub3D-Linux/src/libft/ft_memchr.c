/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:03:28 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 14:03:31 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*ps;
	unsigned int	i;

	ps = (char *)s;
	i = 0;
	while (i < n)
	{
		if (ps[i] == (char)c)
			return ((void *)&(s)[i]);
		else
			i++;
	}
	return (NULL);
}
