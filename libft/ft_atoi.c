/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 16:41:48 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 14:03:18 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(unsigned long nb, int count, int sign)
{
	if (nb > 9223372036854775807 || count > 19)
	{
		if (sign < 0)
			return (0);
		else
			return (-1);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned long	nb;
	int				sign;
	int				count;

	sign = 1;
	nb = 0;
	i = 0;
	count = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		nb = nb * 10 + (str[i] - '0');
		if (str[i] != '0')
			count++;
		i++;
	}
	if (ft_overflow(nb, count, sign) != 1)
		return (ft_overflow(nb, count, sign));
	return ((int)nb * sign);
}
