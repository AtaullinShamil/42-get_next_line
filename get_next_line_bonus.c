/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamil <shamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:17:39 by shamil            #+#    #+#             */
/*   Updated: 2021/12/22 02:03:31 by shamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	str = malloc (sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

static char	*ft_cleaner(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + ft_kol(buffer)));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_reader_gnl(int fd, char *buffer)
{
	int		i;
	char	*str;

	i = 1;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (!ft_proverka(buffer) && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free (str);
			return (NULL);
		}
		str[i] = '\0';
		buffer = ft_strjoin_gnl(buffer, str);
	}
	free (str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[10240];
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_reader_gnl(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	str = ft_cleaner(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (str);
}
