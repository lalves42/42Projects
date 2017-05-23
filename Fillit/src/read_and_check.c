/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:12:58 by lalves            #+#    #+#             */
/*   Updated: 2016/05/03 16:29:23 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	third_check(char *buf)
{
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' ||
		buf[19] != '\n' || (buf[20] != '\n' && buf[20] != '\0'))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
}

static void	second_check(char *buf)
{
	int		sharps;
	int		dots;

	sharps = 0;
	dots = 0;
	while (*buf)
	{
		if (*buf == '#')
			sharps++;
		if (*buf == '.')
			dots++;
		buf++;
	}
	if (sharps != 4 || dots != 12)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
}

static void	first_check(char *buf)
{
	while (*buf)
	{
		if (*buf != '.' && *buf != '#' && *buf != '\n')
		{
			ft_putendl("error");
			exit(EXIT_FAILURE);
		}
		buf++;
	}
}

int			read_tetriminos(int fd, t_tetriminos *ptr)
{
	char	buf[22];
	int		ret;
	int		total;

	total = 0;
	while ((ret = read(fd, buf, 21)) > 0 && total < 26)
	{
		buf[ret] = '\0';
		first_check(buf);
		second_check(buf);
		third_check(buf);
		save_tetriminos(buf, ptr, total);
		total++;
	}
	if ((ret == 0 && total == 0) || buf[20] == '\n')
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	if (ret == -1)
		ft_error("read");
	return (total);
}
