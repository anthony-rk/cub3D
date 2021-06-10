/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:26:53 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 15:26:57 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	len;
	char			*ps;
	unsigned int	i;

	len = ft_strlen(s);
	ps = (char *)s;
	i = 0;
	while (i < len + 1)
	{
		if (ps[i] == (char)c)
			return ((char *)&(s)[i]);
		else
			i++;
	}
	return (0);
}
