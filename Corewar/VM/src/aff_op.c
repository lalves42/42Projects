/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:28:13 by akopera           #+#    #+#             */
/*   Updated: 2017/03/15 01:35:34 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff_op(t_proc *proc, t_op_arg args[3])
{
	int		value;

	if (g_corewar.flags & FLAG_HIDE)
		return ;
	value = 0;
	read_register(get_register(proc->reg, args[0].value), (char *)&value);
	if (!g_corewar.reg_error)
	{
		if (g_corewar.flags & FLAG_NCUR)
		{
			g_corewar.cycle_infos.aff[0] = proc->id;
			g_corewar.cycle_infos.aff[1] = args[0].value;
			g_corewar.cycle_infos.aff[2] = value;
			g_corewar.cycle_infos.aff[3] = proc->carry;
		}
		else
			ft_printf("%c", value);
	}
}
