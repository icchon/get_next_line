/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:18:59 by kaisobe           #+#    #+#             */
/*   Updated: 2024/11/03 11:41:17 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd[4];

	fd[0] = open("files/41_with_nl", O_RDWR);
	printf("1 : %s\n", get_next_line(fd[0]));
	fd[1] = open("files/42_with_nl", O_RDWR);
	printf("2 : %s\n", get_next_line(fd[1]));
	fd[2] = open("files/43_with_nl", O_RDWR);
	printf("3 : %s\n", get_next_line(fd[2]));
	printf("4 : %s\n", get_next_line(fd[0]));
	printf("5 : %s\n", get_next_line(fd[1]));
	printf("6 %s\n", get_next_line(fd[2]));
	printf("7 : %s\n", get_next_line(fd[0]));
	printf("8 : %s\n", get_next_line(fd[1]));
	printf("9 : %s\n", get_next_line(fd[2]));
	fd[3] = open("files/nl", O_RDWR);
	printf("10 : %s\n", get_next_line(fd[3]));
	printf("11 : %s\n", get_next_line(fd[3]));
	write(1, "\n", 1);
	return (0);
}
// while (line1 != NULL)
// {
// 	printf("%s", line1);
// 	free(line1);
// 	line1 = get_next_line(fd1);
// }

// int		fd1;
// char	*line1;
// int		fd2;
// char	*line2;
// fd1 = open("sample1.txt", O_RDONLY);
// fd2 = open("sample2.txt", O_RDONLY);
// line1 = get_next_line(fd1);
// printf("1-1 : %s", line1);
// free(line1);
// line2 = get_next_line(fd2);
// printf("2-1 : %s", line2);
// free(line2);
// line2 = get_next_line(fd2);
// printf("2-2 : %s", line2);
// free(line2);
// line1 = get_next_line(fd1);
// printf("1-2 : %s", line1);
// free(line1);
// close(fd1);
// close(fd2);
// return (0);