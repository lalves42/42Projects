/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 02:11:48 by lalves            #+#    #+#             */
/*   Updated: 2016/05/03 16:35:05 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	find_6(char *s, int i, t_tetriminos *ptr, int total)
{
	if (i < 4 && s[i + 5] == '#' && s[i + 10] == '#' && s[i + 15] == '#')
	{
		ptr[total].a = 5;
		ptr[total].b = 10;
		ptr[total].c = 15;
		return (1);
	}
	return (-1);
}

static int	find_5(char *s, int i, t_tetriminos *ptr, int total)
{
	if (i < 8 && s[i + 1] == '#' && s[i + 6] == '#' && s[i + 11] == '#')
	{
		ptr[total].a = 1;
		ptr[total].b = 6;
		ptr[total].c = 11;
		return (1);
	}
	if (i < 8 && s[i + 1] == '#' && s[i + 5] == '#' && s[i + 10] == '#')
	{
		ptr[total].a = 1;
		ptr[total].b = 5;
		ptr[total].c = 10;
		return (1);
	}
	if (i < 8 && s[i + 5] == '#' && s[i + 6] == '#' && s[i + 10] == '#')
	{
		ptr[total].a = 5;
		ptr[total].b = 6;
		ptr[total].c = 10;
		return (1);
	}
	return (find_6(s, i, ptr, total));
}

static int	find_4(char *s, int i, t_tetriminos *ptr, int total)
{
	if (i < 9 && s[i + 4] == '#' && s[i + 5] == '#' && s[i + 10] == '#')
	{
		ptr[total].a = 4;
		ptr[total].b = 5;
		ptr[total].c = 10;
		return (1);
	}
	if (i < 8 && s[i + 5] == '#' && s[i + 6] == '#' && s[i + 11] == '#')
	{
		ptr[total].a = 5;
		ptr[total].b = 6;
		ptr[total].c = 11;
		return (1);
	}
	if (i < 8 && s[i + 5] == '#' && s[i + 10] == '#' && s[i + 11] == '#')
	{
		ptr[total].a = 5;
		ptr[total].b = 10;
		ptr[total].c = 11;
		return (1);
	}
	return (find_5(s, i, ptr, total));
}

int			find_3(char *s, int i, t_tetriminos *ptr, int total)
{
	if (i < 12 && s[i + 1] == '#' && s[i + 2] == '#' && s[i + 6] == '#')
	{
		ptr[total].a = 1;
		ptr[total].b = 2;
		ptr[total].c = 6;
		return (1);
	}
	if (i < 9 && s[i + 4] == '#' && s[i + 5] == '#' && s[i + 9] == '#')
	{
		ptr[total].a = 4;
		ptr[total].b = 5;
		ptr[total].c = 9;
		return (1);
	}
	if (i < 9 && s[i + 5] == '#' && s[i + 9] == '#' && s[i + 10] == '#')
	{
		ptr[total].a = 5;
		ptr[total].b = 9;
		ptr[total].c = 10;
		return (1);
	}
	return (find_4(s, i, ptr, total));
}
