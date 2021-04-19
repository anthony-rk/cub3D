/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:50:52 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 16:50:54 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *source, const char *find, size_t nb)
{
	size_t	i;
	size_t	j;
	char	*string;

	string = (char *)source;
	i = 0;
	j = 0;
	if (find[0] == '\0')
		return (string);
	while (string[i])
	{
		while (j < nb && find[j] == string[i + j])
		{
			if (ft_strlen(find) + i > nb)
			{
				return (0);
			}
			if (find[j + 1] == '\0' || j == nb)
				return (string + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
