/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strupcase.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:53:50 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 14:53:53 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *s)
{
	int i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
	return (s);
}