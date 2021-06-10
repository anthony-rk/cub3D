/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:54:48 by akowalsk          #+#    #+#             */
/*   Updated: 2021/02/23 17:28:15 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base, int uppercase)
{
	char	*str;
	int		i;
	int		len;

	if (base < 2 || base > 16 || (base != 10 && n < 0))
		return (NULL);
	if (base == 10)
		return (ft_itoa(n));
	len = ft_nbrlen(n, base);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	i = 0;
	while (i < len)
	{
		if (base > 10 && (n % base >= 10 && uppercase))
			str[i++] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'a';
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
