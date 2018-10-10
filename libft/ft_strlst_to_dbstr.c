/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlst_to_dbstr.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 11:36:29 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 11:36:31 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strlst_to_dbstr(t_list *lst)
{
	char	**dbstr;
	int		i;

	i = 0;
	if (!lst)
		return (NULL);
	if (!(dbstr = (char**)ft_memalloc(sizeof(char*) * ft_lstcount(lst))))
		return (NULL);
	dbstr[ft_lstcount(lst)] = NULL;
	while (lst->next != NULL)
	{
		if (!(dbstr[i] = ft_strnew(lst->content_size)))
			return (NULL);
		ft_strcpy(dbstr[i], (char*)lst->content);
		i++;
		lst = lst->next;
	}
	return (dbstr);
}
