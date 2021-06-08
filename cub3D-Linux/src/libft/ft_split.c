/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:00:36 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/11 19:00:39 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int			get_num_words(char const *s, char c)
{
	unsigned int	words;
	unsigned int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static unsigned int			get_next_word_len(const char *s, char c)
{
	unsigned int	i;

	if (*s == c)
		s++;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

static unsigned int			skip_char(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

char						**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	num_strings;
	unsigned int	i;
	unsigned int	next_str_len;
	char			*next_str;

	if (!s)
		return (NULL);
	num_strings = get_num_words(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (num_strings + 1))))
		return (NULL);
	i = 0;
	next_str_len = 0;
	next_str = (char *)s;
	while (i < num_strings)
	{
		next_str += skip_char(next_str, c);
		next_str_len = get_next_word_len(next_str, c);
		if (!(res[i] = (char *)malloc(sizeof(char) * (next_str_len + 1))))
			return (NULL);
		ft_strlcpy(res[i++], next_str, next_str_len + 1);
		next_str += next_str_len + 1;
	}
	res[i] = NULL;
	return (&*res);
}
