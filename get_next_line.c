/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 06:08:59 by icchon            #+#    #+#             */
/*   Updated: 2024/11/01 12:43:04 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	static ssize_t	bytes_read;
	static char		*ptr;
	char			*res;
	int				i;

	// printf("bytes_read ; %ld\n", bytes_read);
	if (!buff[0])
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		printf("byte_read ; %zd\n", bytes_read);
		ptr = buff;
	}
	if (bytes_read <= 0 || *ptr == '\0')
	{
		return (NULL);
	}
	i = 0;
	while (ptr[i])
	{
		if (ptr[i++] == '\n')
			break ;
	}
	if (ptr[i] == '\0')
		i++;
	res = (char *)malloc(sizeof(char) * ft_min(i + 1, bytes_read + 1));
	if (res == NULL)
		return (res);
	i = 0;
	while (bytes_read > 0 && *ptr != '\0')
	{
		if (*ptr == '\n')
		{
			res[i] = *ptr;
			ptr++;
			i++;
			break ;
		}
		res[i] = *ptr;
		ptr++;
		i++;
	}
	if (*ptr == '\0' || bytes_read <= 0)
		res[i] = '\0';
	return (res);
}
