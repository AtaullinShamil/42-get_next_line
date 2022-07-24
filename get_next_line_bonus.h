/* ************************************************************************** */
/*                                                                            */
/*   get_next_line_bonus.h                                                    */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/12/21                                                      */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*ft_checker(char *str);
char	*ft_strjoin_gnl(char	*s1, char	*s2);
int		ft_strlen(char *s);
int		ft_size(char *str);

#endif