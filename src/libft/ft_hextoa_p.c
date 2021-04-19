/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:23:14 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/07 16:23:27 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_p(unsigned long long n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= (-1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*ft_hextoa_p(unsigned long long n)
{
	char	*str;
	int		i;
	int		len;

	len = ft_nbrlen_p(n, 16);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	i = 0;
	while (i < len)
	{
		if ((n % 16 >= 10))
			str[i++] = (n % 16) - 10 + 'a';
		else
			str[i++] = (n % 16) + '0';
		n /= 16;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}


