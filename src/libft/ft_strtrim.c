/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:51:21 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/10 18:51:24 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_left_buffer(char const *s1, char const *set)
{
	int		left_buffer;
	int		i;

	left_buffer = 0;
	i = 0;
	while (set[i] && s1[i])
	{
		if (s1[left_buffer] == '\0')
			return (-1);
		if (s1[left_buffer] == set[i++])
		{
			left_buffer++;
			i = 0;
		}
	}
	return (left_buffer);
}

static int	get_right_buffer(char const *s1, char const *set)
{
	int		right_buffer;
	int		i;
	int		len;

	len = ft_strlen(s1) - 1;
	right_buffer = 0;
	i = 0;
	while (set[i])
	{
		if (s1[len] == set[i++])
		{
			len--;
			right_buffer++;
			i = 0;
		}
	}
	return (right_buffer);
}

static char	*get_empty_string(void)
{
	char *out;

	out = (char *)malloc(sizeof(char) * (1));
	out[0] = '\0';
	return (out);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char			*out;
	unsigned long	i;
	int				lft_buf;
	int				rt_buf;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	lft_buf = get_left_buffer(s1, set);
	if (lft_buf == -1)
		return (get_empty_string());
	rt_buf = get_right_buffer(s1, set);
	out = (char *)malloc(sizeof(char) * (ft_strlen(s1) - lft_buf - rt_buf + 1));
	if (out != NULL)
	{
		i = 0;
		while (i < ft_strlen(s1) - lft_buf - rt_buf)
		{
			out[i] = s1[i + lft_buf];
			i++;
		}
		out[i] = '\0';
	}
	return (out);
}
