/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:50:56 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/12 21:35:12 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "corewar.h"

static int	load_header(int fd, t_player *player)
{
	ssize_t		rcount;
	t_header	header;
	int			magic;

	magic = 0;
	lseek(fd, 0, SEEK_SET);
	rcount = read(fd, (char *)&header, sizeof(t_header));
	if (rcount < 0)
		return (0);
	swap_endianess((char *)&magic, (char *)&header.magic, sizeof(int));
	if (magic != COREWAR_EXEC_MAGIC)
		return (0);
	player->name = ft_strdup(header.prog_name);
	player->comment = ft_strdup(header.comment);
	swap_endianess((char *)&player->prog_size, (char *)&header.prog_size,
																sizeof(int));
	return (1);
}

static int	load_bytecode(int fd, t_player *player)
{
	off_t	offset;
	ssize_t	rcount;
	int		size;

	size = player->prog_size;
	player->bytecode = ft_memalloc(player->prog_size);
	offset = lseek(fd, 0, SEEK_CUR);
	if (lseek(fd, 0, SEEK_END) != (off_t)(sizeof(t_header) + size))
		return (0);
	lseek(fd, offset, SEEK_SET);
	rcount = read(fd, player->bytecode, size);
	if (rcount < 0)
		return (0);
	return (1);
}

static void	read_champion_file(char *path, t_player *player)
{
	int		fd;
	off_t	end_offset;

	if ((fd = open(path, O_RDONLY)) < 0)
		error(ERRNO_OPEN, path);
	end_offset = lseek(fd, 0, SEEK_END);
	if (end_offset < (off_t)sizeof(t_header))
		error(ERRNO_CHAMP_FILE_TOO_SMALL, path);
	if (!load_header(fd, player))
		error(ERRNO_HEADER, path);
	if (end_offset - (off_t)sizeof(t_header) > CHAMP_MAX_SIZE)
		error_max_size(path, end_offset - (off_t)sizeof(t_header));
	if (!load_bytecode(fd, player))
		error(ERRNO_PROG_SIZE, path);
	close(fd);
}

static int	check_number(int count, int number, int force)
{
	t_player	*player;
	int			i;

	i = 0;
	while (i < count)
	{
		player = &g_corewar.players[i];
		if (number == player->number)
		{
			if (force && player->force_number)
				error(ERRNO_CHAMP_NBR, NULL);
			else if (force)
			{
				player->number = check_number(count, number + 1, 0);
				return (number);
			}
			else
				return (check_number(count, number + 1, force));
		}
		i++;
	}
	return (number);
}

void		read_champion(char *av, int number)
{
	static int	idx = 0;
	t_player	*player;
	int			count;

	count = ++g_corewar.player_count;
	g_corewar.players = (t_player *)realloc(g_corewar.players,
			sizeof(t_player) * count);
	player = &g_corewar.players[count - 1];
	ft_bzero(player, sizeof(t_player));
	read_champion_file(av, player);
	if (number > 0)
	{
		player->number = check_number(count - 1, number, 1);
		player->force_number = 1;
	}
	else
	{
		player->number = check_number(count - 1, ++idx, 0);
		player->force_number = 0;
	}
	player->id = count;
}
