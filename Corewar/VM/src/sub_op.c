/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:52 by akopera           #+#    #+#             */
/*   Updated: 2017/03/15 02:25:46 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub_op(t_proc *proc, t_op_arg args[3])
{
	int		sum;
	int		a;
	int		b;

	a = get_value(proc, args, 0, 0);
	b = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	sum = a - b;
	store_register(get_register(proc->reg, args[2].value), (char *)&sum);
	if (g_corewar.reg_error)
		return ;
	if (sum != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}
