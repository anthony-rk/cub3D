/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:24:11 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:24:13 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*ptr1;
	const unsigned char		*ptr2;
	unsigned int			i;

	if (!dst && !src)
		return (NULL);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr2 > ptr1)
	{
		while (i++ < len)
		{
			*(ptr1++) = *(ptr2++);
		}
	}
	else
	{
		i = 0;
		while (i++ < len)
		{
			ptr1[len - i] = ptr2[len - i];
		}
	}
	return (dst);
}
