/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:38:06 by kaisobe           #+#    #+#             */
/*   Updated: 2024/11/02 19:31:18 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_substr(char *s, unsigned int start, size_t len, int to_free)
{
	char	*res;
	int		length;
	int		i;

	if (s == NULL)
		return (NULL);
	length = len * (len <= (ft_strlen(s) - start)) + (ft_strlen(s) - start)
		* (len > ft_strlen(s) - start);
	if (length < 0)
		length = 0;
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
