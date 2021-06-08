/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:08:31 by akowalsk          #+#    #+#             */
/*   Updated: 2021/02/28 13:08:36 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_itoa_zero(void)
{
	char	*out;

	if (!(out = (char *)malloc(sizeof(char) * (2))))
		return (NULL);
	out[0] = '0';
	out[1] = '\0';
	return (out);
}

char				*ft_itoa_unsigned(long int n)
{
	char			*out;
	int				len;
	unsigned int	n_temp;

	n_temp = (n < 0 ? -n : n);
	len = ft_nbrlen(n_temp, 10);
	if (n == 0)
		return (ft_itoa_zero());
	if (!(out = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	out[len--] = '\0';
	while (n_temp)
	{
		out[len--] = '0' + (n_temp % 10);
		n_temp /= 10;
	}
	return (out);
}

