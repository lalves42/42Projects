/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 18:43:15 by lalves            #+#    #+#             */
/*   Updated: 2016/05/05 03:56:04 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <libft.h>
# define BUFF_SIZE 32

int				get_next_line(const int fd, char **line);

typedef struct	s_data
{
	char	*str;
	char	*rest;
	int		ret;
	int		cur_fd;
}				t_data;

#endif
