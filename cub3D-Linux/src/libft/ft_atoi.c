/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:21:54 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:22:01 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_int_overflow(long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (1);
	else
		return (0);
}

static int	get_int_overflow_val(long num)
{
	if (num > 2147483647)
		return (-1);
	else if (num < -2147483648)
		return (0);
	else
		return (num);
}

int	ft_atoi(const char *str)
{
	long			res;
	int				neg;
	unsigned int	i;
	int				is_overflow;

	is_overflow = 0;
	res = 0;
	neg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && (is_overflow == 0))
	{
		is_overflow = is_int_overflow((long)(res * neg));
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (is_overflow != 0)
		return ((int)get_int_overflow_val((long)(res * neg)));
	return ((int)(res * neg));
}
