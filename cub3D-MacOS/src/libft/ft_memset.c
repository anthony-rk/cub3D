/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:24:19 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:24:21 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned int	index;
	unsigned char	*memory;

	index = 0;
	memory = ptr;
	if (len == 0)
		return (ptr);
	while (index < len)
	{
		memory[index] = c;
		index++;
	}
	return (memory);
}
