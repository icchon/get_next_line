/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:18:59 by kaisobe           #+#    #+#             */
/*   Updated: 2024/11/02 19:24:42 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	char	*line1;
	int		fd2;
	char	*line2;

	fd1 = open("sample1.txt", O_RDONLY);
	fd2 = open("sample2.txt", O_RDONLY);
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free(line1);
	line2 = get_next_line(fd2);
	printf("%s", line2);
	free(line2);
	line2 = get_next_line(fd2);
	printf("%s", line2);
	free(line2);
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free(line1);
	close(fd1);
	close(fd2);
	return (0);
}
// while (line1 != NULL)
// {
// 	printf("%s", line1);
// 	free(line1);
// 	line1 = get_next_line(fd1);
// }