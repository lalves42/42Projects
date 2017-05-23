/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:37:02 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:48:11 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
	{
		ERROR_PARAM("ft_putendl_fd");
		return ;
	}
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

#else

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
#endif
