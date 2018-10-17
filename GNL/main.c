/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <fchancel@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 02:02:44 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 16:06:09 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int fd3;
	int fd4;
	int fd5;
	char *line;

	ac = 0;
	fd3 = open(av[1], O_RDONLY);
	fd4 = open(av[2], O_RDONLY);
	fd5 = open(av[3], O_RDONLY);
	printf("lecture fd3 :\n");
	get_next_line(fd3, &line);
	printf("\n");
	printf("lecture fd4 :\n");
	get_next_line(fd4, &line);
	printf("\n");
	printf("lecture fd5 :\n");
	get_next_line(fd5, &line);
	printf("\n");
	printf("lecture fd3 :\n");
	get_next_line(fd3, &line);
	printf("\n");
	printf("lecture fd4 :\n");
	get_next_line(fd4, &line);
	printf("\n");
	printf("lecture fd5 :\n");
	get_next_line(fd5, &line);
	printf("\n");
	printf("lecture fd5 :\n");
	get_next_line(fd5, &line);

}
