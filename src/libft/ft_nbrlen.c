/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:20:15 by akowalsk          #+#    #+#             */
/*   Updated: 2021/02/23 17:21:49 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen(long long n, int base)
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
