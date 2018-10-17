/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 14:22:36 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 16:37:17 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

static t_gnl	*new_lst(int fd)
{
	t_gnl	*elem;

	if (!(elem = (t_gnl*)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	elem->fd = fd;
	elem->str = NULL;
	elem->next = NULL;
	return (elem);
}

static t_gnl	*welcome_fd(int fd, t_gnl **base)
{
	t_gnl	*start;

	start = *base;
	while (*base)
	{
		if (fd == (*base)->fd)
			return (*base);
		*base = (*base)->next;
	}
	*base = start;
	while ((*base)->next != NULL)
		*base = (*base)->next;
	if (!((*base)->next = new_lst(fd)))
		return (NULL);
	*base = (*base)->next;
	//free(start);
	return (*base);
}

// static void		get_str(t_gnl **base)
// {
// 	char	*buf;
// 	int		ret;
// 	char	*tmp;
//
// 	buf = ft_strnew(BUFF_SIZE);
// 	tmp = ft_strnew(0);
// 	while ((ret = read((*base)->fd, buf, BUFF_SIZE)))
// 	{
// 		(*base)->str = ft_strnjoin(tmp, buf, ret);
// 		free(tmp);
// 		tmp = ft_strdup((*base)->str);
// 	}
// 	free(tmp);
// 	free(buf);
// }

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*base;
	t_gnl			*start;

	 *line = NULL;
	 if (fd < 0)
	 	return (-1);
	if (base == NULL)
		if (!(base = new_lst(fd)))
			return (-1);
	start = base;
	base = welcome_fd(fd, &base);
	printf("%d", base->fd);
	// get_str(&base);
	//ft_putstr(base->str);
	base = start;
	//free(start);
	return (0);
}
