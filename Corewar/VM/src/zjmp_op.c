/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:05 by akopera           #+#    #+#             */
/*   Updated: 2017/03/13 23:28:16 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp_op(t_proc *proc, t_op_arg args[3])
{
	if (proc->carry == 1)
		process_move(proc, (short)args[0].value % IDX_MOD);
	else
		process_move(proc, 3);
}
