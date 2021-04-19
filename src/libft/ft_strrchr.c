/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:39:53 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 16:39:57 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;
	char			*ps;

	len = ft_strlen(s);
	ps = (char *)s;
	len++;
	while (len--)
	{
		if (ps[len] == (char)c)
			return ((char*)&(s)[len]);
	}
	return (0);
}
