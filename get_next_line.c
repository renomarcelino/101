/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 06:16:23 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 15:33:34 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int			get_next_line(const int fd, char **line);
{
	int ret;

}
int			main(int ac, char **av)
{
	char	**line;
	int		fd;

	fd = open(av[i], O_RDWR);
	get_next_line(fd, line);
	ft_putdbstr(line, 0);
	return (0);
}
