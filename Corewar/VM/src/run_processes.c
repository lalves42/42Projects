/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:00:36 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/17 16:11:05 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	NOTE: process address may change after do_op,
**	don't use old value
*/

void	run_processes(void)
{
	t_proc	*process;
	int		opcode;
	int		offset;
	int		i;

	i = g_corewar.process_count;
	while (--i >= 0)
	{
		process = &g_corewar.process[i];
		if (process->wait < 0)
		{
			opcode = (int)read_byte(process->pc) - 1;
			if (opcode < OP_COUNT && opcode >= 0)
			{
				process->op = &g_op_tab[opcode];
				process->wait = g_op_tab[opcode].cycles;
			}
		}
		if (--process->wait <= 0)
		{
			offset = process_op(process);
			process_move(&g_corewar.process[i], offset);
		}
	}
}
