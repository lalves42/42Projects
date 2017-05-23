/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:50 by akopera           #+#    #+#             */
/*   Updated: 2017/03/14 22:55:51 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld_op(t_proc *proc, t_op_arg args[3])
{
	int		value;

	value = get_value(proc, args, 0, 0);
	store_register(get_register(proc->reg, args[1].value), (char *)&value);
	if (g_corewar.reg_error)
		return ;
	if (value != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}
