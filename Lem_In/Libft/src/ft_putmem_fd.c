/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:57:38 by lalves            #+#    #+#             */
/*   Updated: 2016/10/14 17:15:23 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putmem_fd(void const *s, size_t size, int fd)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		while (((char*)s)[i] == '\0' && i < size)
		{
			write(fd, "\\0", 2);
			i++;
		}
		if (i < size)
		{
			ft_putchar_fd(((char*)s)[i], fd);
			i++;
		}
	}
}
