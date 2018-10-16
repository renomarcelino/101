/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 06:16:23 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 23:40:49 by rcepre      ###    #+. /#+    ###.fr     */
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

	i = 0;
	if (!gnl->s_tab)
	{
		//printf("alloc de s_tab\n");
		if (!(gnl->s_tab = (char**)ft_memalloc(sizeof(char*))))
			return (-1);
	}
	if (!gnl->fd_tab)
	{
		if (!(gnl->fd_tab = (int*)ft_memalloc(sizeof(int) + 1)))
			return (-1);

		gnl->fd_tab[0] = fd;
		//printf("alloc de fd_tab, fd_tab[%d] = %d\n", i, gnl->fd_tab[0]);
		gnl->fd_tab[1] = -1;
	}
	//printf("recherche du fd %d\n", fd);
	while (gnl->fd_tab[i] >= 0)
	{
		if (gnl->fd_tab[i] == fd)
		{
			//printf("trouve a l'index %d de fd_tab\n", i);
			return (i);
		}
	}
	if (!(gnl->fd_tab = ft_realloc(gnl->fd_tab, sizeof(gnl->fd_tab)
														+ sizeof(int))))
		return (-1);
	//printf("fd non trouve, realloc de fd_tab\n");

	if (!(gnl->s_tab = (char**)ft_realloc(gnl->s_tab, sizeof(gnl->s_tab)
														+ sizeof(char*))))
		return (-1);
	//printf("realloc de s_tab\n");
	gnl->fd_tab[i] = fd;
	gnl->s_tab[i] = NULL;
	return (i);
}

static int			get_str(int fd, t_gnl *gnl, int i)
{
	char			*buf;
	char			*tmp;
	int				ret;


	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	//printf("alloc du buf\n");
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (-1);
	//printf("alloc du tmp\n");
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		tmp = ft_strnjoin(tmp, buf, ret);
	}
	//printf("read && strnjoin, taille chaine totale = %zu\n", ft_strlen(tmp));

	if (!(gnl->s_tab[i] = ft_strnew(ft_strlen(tmp))))
		return (-1);
	//printf("alloc de s_tab[%d]\n", i);
	gnl->s_tab[i] = tmp;
	//printf("cpoie de tmp dans chaine, taille  = %zu\n", ft_strlen(gnl->s_tab[i]));
	return (0);
}

static int			get_line(char **s, char **line)
{
	int		i;
	char	*cpy;
	int		bol;

	bol = 0;
	i = 0;
	cpy = ft_strdup(*s);
	//printf("alloc d'une copie de l a chaine\n");
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	//printf("ballayage j'usqua \\n ou \\0\n");
	if ((*s)[i] == '\0')
		bol = 1;
	//printf("*s est != de \\0\n");
	*line = ft_strsub(*s, 0, i);
	//printf("on fous la chaine dans *line\n");
	if (bol == 0)
		i++;
	if (bol == 0)
	{
		cpy = ft_strsub(*s, i, ft_strlen(*s) - i);
		//printf("on copie \n");
		free(*s);
		//printf("on free le bout qu'on veut plus wooola \n");
		*s = ft_strdup(cpy);
		//printf("on strdup !!! wooola!!! \n");
	}
	return (bol == 1 ? 0 : 1);
}

int					get_next_line(const int fd, char **line)
{
	int				i;
	static t_gnl	*gnl;

	if (gnl == NULL)
		if (!( gnl = init_struct()))
			return (-1);
	if ((i = welcome_fd(fd, gnl) == -1))
		return (-1);
	if (!gnl->s_tab[i])
		if ((get_str(fd, gnl, i) == -1))
			return (-1);
	return (get_line(&(gnl->s_tab[i]), line));
}
