/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:10:39 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/22 21:51:54 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap_endianess(char *dst, char *src, size_t type_size)
{
	int		i;

	i = type_size - 1;
	while (i >= 0)
	{
		dst[i] = src[type_size - (i + 1)];
		i--;
	}
}
