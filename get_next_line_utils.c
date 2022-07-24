/* ************************************************************************** */
/*                                                                            */
/*   get_next_line_utils.c                                                    */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/12/23                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_checker(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}

static	char	*ft_malloc(char *str)
{
	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	if (!s1)
		s1 = ft_malloc(s1);
	if (!s1 || !s2)
		return (NULL);
	buffer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		buffer[i++] = s1[j++];
	j = 0;
	while (s2[j])
		buffer[i++] = s2[j++];
	buffer[i] = '\0';
	free(s1);
	return (buffer);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (2);
	else
		return (1);
}
