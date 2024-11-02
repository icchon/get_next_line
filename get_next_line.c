/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 06:08:59 by icchon            #+#    #+#             */
/*   Updated: 2024/11/02 12:11:17 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_safely_strjoin(char *s1, char *s2, int to_free_s1, int to_free_s2)
{
	char	*res;
	size_t	length;
	size_t	i;

	length = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	while (i < length)
	{
		res[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	res[i] = '\0';
	if (to_free_s1)
		free(s1);
	if (to_free_s2)
		free(s2);
	return (res);
}

char	*ft_concat(char *line, char *src, char **rest, int to_free_rest)
{
	int		i;
	char	*concat_part;

	i = 0;
	while (src[i] && src[i++] == '\n')
	{
		concat_part = ft_substr(src, 0, (i), 0);
		*rest = ft_substr(src, (i), BUFFER_SIZE, to_free_rest);
		return (ft_safely_strjoin(line, concat_part, 1, 1));
	}
	return (ft_safely_strjoin(line, src, 1, to_free_rest));
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*concat_part;
	static char	*rest = NULL;
	char		buff[BUFFER_SIZE + 1];
	int			i;

	ft_memset(buff, 0, BUFFER_SIZE + 1);
	if (rest == NULL)
		rest = ft_strdup("");
	line = ft_strdup("");
	i = 0;
	while (rest[i] && rest[i++] == '\n')
	{
		concat_part = ft_substr(rest, 0, (i), 0);
		rest = ft_substr(rest, (i), BUFFER_SIZE, 1);
		return (ft_safely_strjoin(line, concat_part, 1, 1));
	}
	line = ft_safely_strjoin(line, rest, 1, 1);
	rest = NULL;
	if (read(fd, buff, BUFFER_SIZE) <= 0 && !line[0])
		return (free(line), NULL);
	i = 0;
	return (ft_concat(line, buff, &rest, 0));
}
