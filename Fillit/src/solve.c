/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 02:26:48 by lalves            #+#    #+#             */
/*   Updated: 2016/05/03 16:28:25 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	clear_tetri(t_square *sqr, char c)
{
	int		i;

	i = 0;
	while (sqr->grid[i])
	{
		if (sqr->grid[i] == c)
			sqr->grid[i] = '.';
		i++;
	}
}

static int	new_pos(t_square *sqr, char c)
{
	int		i;

	i = 0;
	while (sqr->grid[i] && sqr->grid[i] != c)
		i++;
	return (i + 1);
}

static int	place_tetri(t_tetriminos *ptr, t_square *sqr, int i)
{
	int max;
	int total;

	max = ft_strlen(sqr->grid) - 1;
	total = sqr->total_tmp;
	convert(ptr, sqr);
	while (sqr->grid[i])
	{
		if ((i + ptr[total].f) > max)
			break ;
		if (sqr->grid[i] == '.' && sqr->grid[i + ptr[total].d] == '.'
			&& sqr->grid[i + ptr[total].e] == '.'
			&& sqr->grid[i + ptr[total].f] == '.')
		{
			sqr->grid[i] = ptr[total].letter;
			sqr->grid[i + ptr[total].d] = ptr[total].letter;
			sqr->grid[i + ptr[total].e] = ptr[total].letter;
			sqr->grid[i + ptr[total].f] = ptr[total].letter;
			return (0);
		}
		i++;
	}
	return (-1);
}

static int	solve_recursive(t_tetriminos *ptr, t_square *sqr, int pos)
{
	if (place_tetri(ptr, sqr, pos) == -1)
		return (-1);
	else
	{
		sqr->total_tmp++;
		if (sqr->total_tmp < sqr->total)
		{
			if (solve_recursive(ptr, sqr, 0) == -1)
			{
				sqr->total_tmp--;
				pos = new_pos(sqr, ptr[sqr->total_tmp].letter);
				clear_tetri(sqr, ptr[sqr->total_tmp].letter);
				if (solve_recursive(ptr, sqr, pos) == -1)
					return (-1);
			}
		}
	}
	return (1);
}

void		solve(t_tetriminos *ptr, t_square *sqr)
{
	while (sqr->total_tmp < sqr->total)
	{
		if (solve_recursive(ptr, sqr, 0) == -1)
		{
			ft_strdel(&(sqr->grid));
			sqr->size++;
			sqr->total_tmp = 0;
			init_grid(sqr);
		}
	}
	write(1, sqr->grid, ft_strlen(sqr->grid));
	ft_strdel(&(sqr->grid));
	ft_memdel((void**)&sqr);
}
