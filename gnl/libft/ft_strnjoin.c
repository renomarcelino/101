/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 07:02:10 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 10:28:22 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	int		l1;
	int		l2;
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(str = ft_strnew(n > l2 ? l1 + l2 : l1 + n)))
		return (NULL);
	l1 = 0;
	while (s1[l1])
		str[i++] = s1[l1++];
	l2 = 0;
	while (s2[l2] && l2 < n)
		str[i++] = s2[l2++];
	return (str);
}
