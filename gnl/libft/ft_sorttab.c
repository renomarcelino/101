/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sorttab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 17:22:16 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 17:22:17 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sorttab(int *tab, int size)
{
	int i;
	int j;
	int swap;

	i = 1;
	while (i < size)
	{
		j = i;
		while (tab[j] < tab[j - 1] && j > 0)
		{
			swap = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = swap;
			j--;
		}
		i++;
	}
	return (tab);
}
