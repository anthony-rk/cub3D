/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:33:36 by akowalsk          #+#    #+#             */
/*   Updated: 2021/02/13 20:20:36 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_append_line(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	*line = ft_substr(*s, 0, len);
	tmp = ft_strdup(&(*s)[len + 1]);
	free(*s);
	*s = tmp;
	return (1);
}

static int	ft_final_read(char **s, char **line)
{
	if (*s == NULL)
	{
		*line = malloc(sizeof(char) * 1);
		if (!(*line))
			return (-1);
		(*line)[0] = '\0';
	}
	else if (*s[0] == '\0')
	{
		*line = malloc(sizeof(char) * 1);
		if (!(*line))
			return (-1);
		(*line)[0] = '\0';
		free(*s);
		*s = NULL;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (0);
}

static char	*ft_read_til_nl(char **s, char *buf, int ret)
{
	char		*tmp;

	buf[ret] = '\0';
	if (!*s)
		*s = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(*s, buf);
		free(*s);
		*s = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
	}
	return (*s);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*static_reader[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd > 1024)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		static_reader[fd] = ft_read_til_nl(&static_reader[fd], buf, ret);
		if (ft_strrchr(static_reader[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if ((ret == 0 && !static_reader[fd]) ||
				(ret == 0 && !(ft_strrchr(static_reader[fd], '\n'))))
		return (ft_final_read(&static_reader[fd], line));
	else
		return (ft_append_line(&static_reader[fd], line));
}
