/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlst_to_dbstr.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 11:36:29 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:14:57 by rcepre      ###    #+. /#+    ###.fr     */
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
	if (!(dbstr = (char**)ft_memalloc(sizeof(char*) * (ft_lstcount(lst) + 1))))
		return (NULL);
	while (lst)
	{
		if (!(dbstr[i] = ft_strnew(lst->content_size)))
			return (NULL);
		ft_strcpy(dbstr[i], (char*)lst->content);
		i++;
		lst = lst->next;
	}
	dbstr[i] = NULL;
	return (dbstr);
}
