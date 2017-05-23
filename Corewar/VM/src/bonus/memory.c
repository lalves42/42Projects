/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:41:56 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/23 08:49:29 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	player_bytes(t_cycle_infos *infos, t_player *player, char *pc)
{
	int		start;
	int		i;

	start = pc - infos->arena;
	i = start + player->prog_size - 1;
	while (i >= start)
	{
		infos->byte_infos[i].number = player->id;
		i--;
	}
}

void		init_memory(t_cycle_infos *infos)
{
	int			i;

	i = 0;
	ft_bzero(&infos->byte_infos, MEM_SIZE);
	while (i < g_corewar.player_count)
	{
		player_bytes(infos, &g_corewar.players[i], g_corewar.process[i].pc);
		i++;
	}
}
