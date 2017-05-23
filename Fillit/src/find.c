/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:42:11 by lalves            #+#    #+#             */
/*   Updated: 2016/05/03 16:34:50 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	find_2(char *s, int i, t_tetriminos *ptr, int total)
{
	if (i < 12 && s[i + 1] == '#' && s[i + 2] == '#' && s[i + 5] == '#')
	{
		ptr[total].a = 1;
		ptr[total].b = 2;
		ptr[total].c = 5;
		return (1);
	}
	if (i < 12 && s[i + 5] == '#' && s[i + 6] == '#' && s[i + 7] == '#')
	{
		ptr[total].a = 5;
		ptr[total].b = 6;
		ptr[total].c = 7;
		return (1);
	}
	if (i < 12 && s[i + 1] == '#' && s[i + 2] == '#' && s[i + 7] == '#')
	{
		ptr[total].a = 1;
		ptr[total].b = 2;
		ptr[total].c = 7;
		return (1);
	}
	return (find_3(s, i, ptr, total));
}

static int	find_1(char *s, int i, t_tetriminos *ptr, int total)
{
	if (i < 13 && s[i + 4] == '#' && s[i + 5] == '#' && s[i + 6] == '#')
	{
		ptr[total].a = 4;
		ptr[total].b = 5;
		ptr[total].c = 6;
		return (1);
	}
	if (i < 13 && s[i + 1] == '#' && s[i + 5] == '#' && s[i + 6] == '#')
	{
		ptr[total].a = 1;
		ptr[total].b = 5;
		ptr[total].c = 6;
		return (1);
	}
	if (i < 12 && s[i + 1] == '#' && s[i + 6] == '#' && s[i + 7] == '#')
	{
		ptr[total].a = 1;
		ptr[total].b = 6;
		ptr[total].c = 7;
		return (1);
	}
	return (find_2(s, i, ptr, total));
}

static int	find(char *s, int i, t_tetriminos *ptr, int total)
{
	if (i < 16 && s[i + 1] == '#' && s[i + 2] == '#' && s[i + 3] == '#')
	{
		ptr[total].a = 1;
		ptr[total].b = 2;
		ptr[total].c = 3;
		return (1);
	}
	if (i < 14 && s[i + 3] == '#' && s[i + 4] == '#' && s[i + 5] == '#')
	{
		ptr[total].a = 3;
		ptr[total].b = 4;
		ptr[total].c = 5;
		return (1);
	}
	if (i < 13 && s[i + 1] == '#' && s[i + 4] == '#' && s[i + 5] == '#')
	{
		ptr[total].a = 1;
		ptr[total].b = 4;
		ptr[total].c = 5;
		return (1);
	}
	return (find_1(s, i, ptr, total));
}

static int	find_tetriminos(char *s, t_tetriminos *ptr, int total)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '#')
		i++;
	return (find(s, i, ptr, total));
}

void		save_tetriminos(char *buf, t_tetriminos *ptr, int total)
{
	if (find_tetriminos(buf, ptr, total) == -1)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	ptr[total].letter = 'A' + total;
}
