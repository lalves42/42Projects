/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 02:25:33 by lalves            #+#    #+#             */
/*   Updated: 2016/05/03 16:25:31 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		convert_c(t_tetriminos *ptr, t_square *sqr, int total)
{
	if (ptr[total].c > 3)
	{
		if (ptr[total].c == 5)
			ptr[total].f = sqr->size + 1;
		if (ptr[total].c == 6)
			ptr[total].f = sqr->size + 2;
		if (ptr[total].c == 7)
			ptr[total].f = sqr->size + 3;
		if (ptr[total].c == 9)
			ptr[total].f = 2 * (sqr->size + 1) - 1;
		if (ptr[total].c == 10)
			ptr[total].f = 2 * (sqr->size + 1);
		if (ptr[total].c == 11)
			ptr[total].f = 2 * (sqr->size + 1) + 1;
		if (ptr[total].c == 15)
			ptr[total].f = 3 * (sqr->size + 1);
	}
}

void		convert_b(t_tetriminos *ptr, t_square *sqr, int total)
{
	if (ptr[total].b > 2)
	{
		if (ptr[total].b == 4)
			ptr[total].e = sqr->size;
		if (ptr[total].b == 5)
			ptr[total].e = sqr->size + 1;
		if (ptr[total].b == 6)
			ptr[total].e = sqr->size + 2;
		if (ptr[total].b == 9)
			ptr[total].e = 2 * (sqr->size + 1) - 1;
		if (ptr[total].b == 10)
			ptr[total].e = 2 * (sqr->size + 1);
	}
	convert_c(ptr, sqr, total);
}

void		convert(t_tetriminos *ptr, t_square *sqr)
{
	int total;

	total = sqr->total_tmp;
	ptr[total].d = ptr[total].a;
	ptr[total].e = ptr[total].b;
	ptr[total].f = ptr[total].c;
	if (ptr[total].a > 1)
	{
		if (ptr[total].a == 3)
			ptr[total].d = sqr->size - 1;
		if (ptr[total].a == 4)
			ptr[total].d = sqr->size;
		if (ptr[total].a == 5)
			ptr[total].d = sqr->size + 1;
	}
	convert_b(ptr, sqr, total);
}
