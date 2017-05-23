/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:07:54 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/17 16:20:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	mark_bytes(t_cycle_infos *infos)
{
	t_byte_infos	*byte;
	char			*pc;
	int				i;

	i = 0;
	while (i < MEM_SIZE)
	{
		byte = &infos->byte_infos[i];
		byte->pc = 0;
		if (g_corewar.state & (STATE_RUNNING | STATE_STEP))
		{
			byte->live -= (byte->live > 0) ? 1 : 0;
			byte->op -= (byte->op > 0) ? 1 : 0;
		}
		i++;
	}
	i = g_corewar.process_count;
	while (--i >= 0)
	{
		pc = g_corewar.process[i].pc;
		if (pc >= infos->arena + MEM_SIZE)
			infos->byte_infos[0].pc |= 1;
		else
			infos->byte_infos[pc - infos->arena].pc |= 1;
	}
}
