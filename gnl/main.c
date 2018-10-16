/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:58:49 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 15:15:04 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int					main(int ac, char **av)
{
	int				fd;
	int 			fd2;
	char			*line;

		fd = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		if (fd == -1 || fd2 == -1)
			return (1);
		ac = 0;

	ft_putnbr(get_next_line(fd, &line));
	ft_putendl(line);
	// ft_putnbr(get_next_line(fd2, &line));
	// ft_putendl(line);
	// ft_putnbr(get_next_line(fd, &line));
	// ft_putendl(line);
	// ft_putnbr(get_next_line(fd2, &line));
	// ft_putendl(line);
	// ft_putnbr(get_next_line(fd2, &line));
	// ft_putendl(line);
    //
	// ft_putnbr(get_next_line(fd2, &line));
	// ft_putendl(line);

	// while (get_next_line(fd, &line))
	// 	ft_putendl(line);
	// while (get_next_line(fd2, &line))
	// 	ft_putendl(line);





	return (0);
}
