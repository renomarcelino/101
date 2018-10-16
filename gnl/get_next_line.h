/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 06:14:34 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 10:32:18 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include <fcntl.h>


typedef struct 			s_gnl
{
	char				**s_tab;
	int					*fd_tab;
}						t_gnl;

int			get_next_line(const int fd, char **line);


#endif
