/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 02:27:21 by lalves            #+#    #+#             */
/*   Updated: 2016/05/03 16:27:21 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		helper(t_square *sqr)
{
	ft_memdel((void**)&sqr);
	ft_error("malloc");
}

void			init_grid(t_square *sqr)
{
	int i;
	int size;
	int len;

	i = 0;
	size = sqr->size;
	len = sqr->size * (sqr->size + 1) + 1;
	sqr->grid = (char*)malloc(sizeof(char) * len);
	if (!sqr->grid)
		helper(sqr);
	while (i < (len - 1))
	{
		while (size > 0)
		{
			sqr->grid[i] = '.';
			i++;
			size--;
		}
		sqr->grid[i] = '\n';
		size = sqr->size;
		i++;
	}
	sqr->grid[i] = '\0';
}
