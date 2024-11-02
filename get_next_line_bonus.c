/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 06:08:59 by icchon            #+#    #+#             */
/*   Updated: 2024/11/02 19:31:41 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_concat(char *line, char *src, char **rest, int to_free_src)
{
	int		i;
	char	*concat_part;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		while (src[i++] == '\n')
		{
			concat_part = ft_substr(src, 0, (i), 0);
			*rest = ft_substr(src, (i), BUFFER_SIZE, to_free_src);
			return (ft_safely_strjoin(line, concat_part, 1, 1));
		}
	}
	return (NULL);
}

t_file_list	*ft_lstnew(int fd, char *rest)
{
	t_file_list	*node;

	node = (t_file_list *)malloc(sizeof(t_file_list) * 1);
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->rest = rest;
	node->next = NULL;
	return (node);
}

t_file_list	*ft_get_elem(t_file_list **lst, int fd)
{
	t_file_list	*node;

	node = *lst;
	while (node != NULL)
	{
		if (node->fd == fd)
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

t_file_list	*ft_init(char *buff, t_file_list *node, t_file_list *lst, int fd)
{
	if (node == NULL)
	{
		node = ft_lstnew(fd, NULL);
		if (node == NULL)
			return (NULL);
		node->next = lst;
		lst = node;
	}
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	if (node->rest == NULL)
	{
		node->rest = ft_strdup("");
		if (node->rest == NULL)
			return (NULL);
	}
	return (node);
}

char	*get_next_line(int fd)
{
	char				*line;
	char				buff[BUFFER_SIZE + 1];
	static t_file_list	*lst = NULL;
	t_file_list			*node;
	char				*tmp;

	node = ft_get_elem(&lst, fd);
	node = ft_init(buff, node, lst, fd);
	if (node == NULL)
		return (NULL);
	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	tmp = ft_concat(line, node->rest, &(node->rest), 1);
	if (tmp != NULL)
		return (tmp);
	line = ft_safely_strjoin(line, node->rest, 1, 1);
	node->rest = NULL;
	if (read(fd, buff, BUFFER_SIZE) <= 0 && !line[0])
		return (free(line), free(node), NULL);
	tmp = ft_concat(line, buff, &(node->rest), 0);
	if (tmp == NULL)
		tmp = ft_safely_strjoin(line, buff, 1, 0);
	return (tmp);
}
