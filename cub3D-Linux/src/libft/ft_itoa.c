/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:32:01 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/14 15:32:15 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char					*ft_itoa_zero(void)
{
	char	*out;

	if (!(out = (char *)malloc(sizeof(char) * (2))))
		return (NULL);
	out[0] = '0';
	out[1] = '\0';
	return (out);
}

static unsigned int			ft_num_len(int n)
{
	unsigned int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char						*ft_itoa(int n)
{
	char			*out;
	unsigned int	len;
	unsigned int	n_temp;

	n_temp = (n < 0 ? -n : n);
	len = ft_num_len(n_temp);
	if (n < 0)
		len++;
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
	if (n < 0)
		out[len] = '-';
	return (out);
}
