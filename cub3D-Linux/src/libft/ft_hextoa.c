/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:46:59 by akowalsk          #+#    #+#             */
/*   Updated: 2021/02/26 18:47:03 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hextoa(unsigned long long n)
{
	char	*str;
	int		i;
	int		len;

	len = ft_nbrlen(n, 16);
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
