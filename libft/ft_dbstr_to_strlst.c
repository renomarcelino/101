/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dbstr_to_strlst.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 08:15:10 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 08:15:11 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_dbstr_to_strlst(char **dbstr)
{
	int		i;
	t_list	*lst;
	t_list	*begin_list;

	if (!dbstr)
		return (NULL);
	i = 0;
	if (!(lst = ft_lstnew(dbstr[i], sizeof(char*))))
		return (NULL);
	begin_list = lst;
	while (dbstr[i++] != NULL)
	{
		if (!(lst->next = ft_lstnew(dbstr[i], sizeof(char*))))
			return (NULL);
		lst = lst->next;
	}
	return (begin_list);
}
