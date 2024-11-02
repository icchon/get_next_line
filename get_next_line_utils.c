/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:09:33 by kaisobe           #+#    #+#             */
/*   Updated: 2024/11/02 12:27:56 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (s);
}

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int to_free)
{
	char	*res;
	int		length;
	int		i;

	length = -1 * ft_min(0, -1 * ft_min(len, ft_strlen(s) - start));
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < length)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	if (to_free)
		free(s);
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
