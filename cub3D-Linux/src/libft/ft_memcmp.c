/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:48:25 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 14:48:28 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;
	unsigned int		i;

	if (n == 0 || s1 == s2)
		return (0);
	ptrs1 = (const unsigned char *)s1;
	ptrs2 = (const unsigned char *)s2;
	i = 0;
	while (ptrs1[i] == ptrs2[i] && i < n - 1)
		i++;
	return (ptrs1[i] - ptrs2[i]);
}
