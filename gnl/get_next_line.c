/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 06:16:23 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 15:13:16 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

static	t_gnl		*init_struct(void)
{
	t_gnl			*elem;

	if (!(elem = (t_gnl*)ft_memalloc(sizeof(t_gnl*))))
		return (NULL);
	elem->s_tab = NULL;
	elem->fd_tab = NULL;
	return (elem);
}

static int			welcome_fd(int fd, t_gnl *gnl)
{
	int i;

	i = -1;
	if (!gnl->s_tab)
		if (!(gnl->s_tab = (char**)ft_memalloc(sizeof(char*))))
			return (-1);
				ft_putstr("HEEEEELLLLLOOOOOi1\n");
	if (gnl->fd_tab == NULL)
	{
		if (!(gnl->fd_tab = (int*)ft_memalloc(sizeof(int) + 1)))
			return (-1);
		gnl->fd_tab[0] = fd;
		gnl->fd_tab[1] = -1;
	}
		ft_putstr("HEEEEELLLLLOOOOO2\n");
	while (gnl->fd_tab[i++] >= 0)
		if (gnl->fd_tab[i] == fd)
			return (i);
				ft_putstr("HEEEEELLLLLOOOOO3\n");
	if (!(gnl->fd_tab = ft_realloc(gnl->fd_tab, sizeof(gnl->fd_tab)
														+ sizeof(int))))
		return (-1);
	if (!(gnl->s_tab = (char**)ft_realloc(gnl->s_tab, sizeof(gnl->s_tab)
														+ sizeof(char*))))
		return (-1);
	gnl->fd_tab[i] = fd;
	gnl->s_tab[i] = NULL;
	ft_putstr("HEEEEELLLLLOOOOO4\n");
	return (i);
}

static int			get_str(int fd, t_gnl *gnl, int i)
{
	char			*buf;
	char			*tmp;
	int				ret;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
		tmp = ft_strnjoin(tmp, buf, ret);
	if (!(gnl->s_tab[i] = ft_strnew(ft_strlen(tmp))))
		return (-1);
	gnl->s_tab[i] = tmp;
	return (0);
}

static int			get_line(char **s, char **line)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = ft_strdup(*s);
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\0')
		return (0);
	*line = ft_strsub(*s, 0, i);
	i++;
	cpy = ft_strsub(*s, i, ft_strlen(*s) - i);
	free(*s);
	*s = ft_strdup(cpy);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				i;
	static t_gnl	*gnl;

	if (gnl == NULL)
		if (!( gnl = init_struct()))
			return (-1);
	if (!(i = welcome_fd(fd, gnl) == -1))
		return (-1);
	if (!gnl->s_tab[i])
		if (!(get_str(fd, gnl, i) == -1))
			return (-1);
	if (get_line(&(gnl->s_tab[i]), line) == 0)
		return (0);
	return (1);
}
