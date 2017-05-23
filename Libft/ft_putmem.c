/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:19:55 by lalves            #+#    #+#             */
/*   Updated: 2015/12/17 19:07:09 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(void const *s, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		while (((char*)s)[i] == '\0')
		{
			write(1, "\\0", 2);
			i++;
		}
		if (i < size)
		{
			ft_putchar(((char*)s)[i]);
			i++;
		}
	}
}
