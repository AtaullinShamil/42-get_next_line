/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamil <shamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:32:10 by ntojamur          #+#    #+#             */
/*   Updated: 2021/12/22 20:56:56 by shamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*buffer;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_reader_gnl(fd, buffer);
	if (!buffer)
		return (NULL);
	str = ft_cleaner(buffer);
	buffer = ft_next(buffer);
	return (str);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include "get_next_line.h"

// int	main(void)
// {
// 	printf("%s\n", get_next_line(1));
// 	return (0);
// }

// #include <stdio.h>
// #include <fcntl.h>
// #include "get_next_line_bonus.h"

// int	main(void)
// {
// 	int	fd1;
// 	int	fd2;

// 	fd1 = open("first.txt", O_RDONLY);
// 	fd2 = open("second.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd1));
// 	printf("%s\n", get_next_line(fd2));
// 	printf("%s\n", get_next_line(fd1));
// 	printf("%s\n", get_next_line(fd2));
// 	printf("%s\n", get_next_line(fd1));
// 	printf("%s\n", get_next_line(fd2));
// 	return (0);
// }