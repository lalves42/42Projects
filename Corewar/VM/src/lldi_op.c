/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:22 by akopera           #+#    #+#             */
/*   Updated: 2017/03/16 18:11:00 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lldi_op(t_proc *proc, t_op_arg args[3])
{
	t_reg	*dst_reg;
	int		reg_value;
	int		offset;
	int		a;
	int		b;

	a = get_value(proc, args, 0, 1);
	b = get_value(proc, args, 1, 1);
	if (g_corewar.reg_error)
		return ;
	offset = a + b;
	if ((dst_reg = get_register(proc->reg, args[2].value)))
		read_range((char *)dst_reg, proc->pc + offset, REG_SIZE);
	reg_value = 0;
	read_register(get_register(proc->reg, args[2].value), (char *)&reg_value);
	if (g_corewar.reg_error)
		return ;
	if (reg_value != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}
