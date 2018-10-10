/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 08:41:06 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 10:06:11 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int nb, int base)
{
	int		i;
	char	*str;
	int		tmp;

	i = 0;
	tmp = nb;
	while (tmp > base)
	{
		tmp /= base;
		i++;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i > 0)
	{
		tmp = nb % base;
		str[i--] = tmp + '0';
		nb /= base;
	}
	return (str);
}
