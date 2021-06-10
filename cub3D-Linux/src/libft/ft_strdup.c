/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:01:10 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 16:01:20 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	len;
	unsigned int	i;
	char			*out;

	len = ft_strlen(s1);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		out[i] = s1[i];
		i++;
	}
	return (out);
}
