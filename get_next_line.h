/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 06:05:51 by icchon            #+#    #+#             */
/*   Updated: 2024/11/02 12:28:06 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// # define MIN(x, y) (((x) <= (y)) * (x) + ((x) > (y)) * (y))
// # define MAX(x, y) (((x) >= (y)) * (x) + ((x) < (y)) * (y))

char	*get_next_line(int fd);
char	*ft_safely_strjoin(char *s1, char *s2, int to_free_s1, int to_free_s2);
char	*ft_concat(char *line, char *src, char **rest, int to_free_rest);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len, int to_free);
char	*ft_strdup(const char *s);

#endif