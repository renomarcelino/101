/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 08:51:20 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 10:15:28 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dest;
	size_t	i;

	i = 0;
	if (!(dest = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(dest, size + 1);
	return (dest);
}
