/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:38:31 by kaisobe           #+#    #+#             */
/*   Updated: 2024/11/03 11:47:07 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE > 1000000 || BUFFER_SIZE < 0
#   error "Invalid BUFFER_SIZE"
#  endif
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_file_list
{
	int					fd;
	char				*rest;
	struct s_file_list	*next;
}						t_file_list;

char					*get_next_line(int fd);
char					*ft_safely_strjoin(char *s1, char *s2, int to_free_s1,
							int to_free_s2);
char					*ft_concat(char *line, char *src, char **rest,
							int to_free_rest);
size_t					ft_strlen(const char *s);
void					*mem(void *s, int c, size_t n);
char					*ft_substr(char *s, unsigned int start, size_t len,
							int to_free);
char					*ft_strdup(const char *s);

#endif