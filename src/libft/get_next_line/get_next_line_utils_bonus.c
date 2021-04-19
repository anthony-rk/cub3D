/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:34:02 by akowalsk          #+#    #+#             */
/*   Updated: 2021/02/06 13:34:05 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*out;
	unsigned int	i;
	unsigned int	j;
	unsigned int	out_len;

	if (!s1 || !s2)
		return (NULL);
	out_len = ft_strlen(s1) + ft_strlen(s2);
	out = (char *)malloc(sizeof(char) * (out_len + 1));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		out[i + j] = s2[j];
		j++;
	}
	out[i + j] = '\0';
	return (out);
}

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

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;
	char			*ps;

	len = ft_strlen(s);
	ps = (char *)s;
	len++;
	while (len--)
	{
		if (ps[len] == (char)c)
			return ((char *)&(s)[len]);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[0] = '\0';
	if (start > ft_strlen(s))
		return (res);
	while (s[start] && i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
