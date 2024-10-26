/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icchon <icchon@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-25 06:08:59 by icchon            #+#    #+#             */
/*   Updated: 2024-10-25 06:08:59 by icchon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	static ssize_t	bytes_read;
	static char		*ptr;
	char			*res;
	int				i;
	int				j;

	if (!buff[0])
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		ptr = buff;
	}
	if (bytes_read <= 0)
	{
		return (NULL);
	}
	i = 0;
	while (ptr[i] != '\n')
	{
		i++;
	}
	i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*ptr != '\n' && bytes_read > 0)
	{
		res[i] = *ptr;
		i++;
		*ptr++;
		bytes_read--;
	}
	res[i] = *ptr;
	*ptr++;
	bytes_read--;
	res[i + 1] = '\0';
	return (res);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("sample.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
