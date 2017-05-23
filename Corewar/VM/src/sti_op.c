/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:47 by akopera           #+#    #+#             */
/*   Updated: 2017/03/15 01:40:12 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti_op(t_proc *proc, t_op_arg args[3])
{
	int		champ_number;
	int		offset;
	int		a;
	int		b;

	a = get_value(proc, args, 1, 0);
	b = get_value(proc, args, 2, 0);
	if (g_corewar.reg_error)
		return ;
	offset = (a + b) % IDX_MOD;
	champ_number = 0;
	read_register(get_register(proc->reg, 1), (char *)&champ_number);
	write_register(get_register(proc->reg, args[0].value), proc->pc + offset,
																champ_number);
}
