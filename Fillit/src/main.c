/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:51:55 by lalves            #+#    #+#             */
/*   Updated: 2016/05/03 16:28:11 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		find_size(t_square *sqr, int total)
{
	int x;

	x = 0;
	while ((x * x) < (4 * total))
		x++;
	sqr->size = x;
}

static void		init_sqr(t_square **sqr, int total)
{
	*sqr = (t_square*)malloc(sizeof(t_square));
	if (!(*sqr))
		ft_error("malloc");
	(*sqr)->total = total;
	(*sqr)->total_tmp = 0;
	find_size(*sqr, total);
	init_grid(*sqr);
}

static void		close_file(int fd)
{
	if (close(fd) == -1)
		ft_error("close");
}

static int		open_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("open");
	return (fd);
}

int				main(int argc, char **argv)
{
	t_tetriminos	ptr[26];
	t_square		*sqr;
	int				fd;
	int				total;

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		exit(EXIT_FAILURE);
	}
	sqr = NULL;
	fd = open_file(argv[1]);
	total = read_tetriminos(fd, ptr);
	close_file(fd);
	init_sqr(&sqr, total);
	solve(ptr, sqr);
	return (0);
}
