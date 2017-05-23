/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:26:17 by akopera           #+#    #+#             */
/*   Updated: 2017/03/18 13:08:43 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fork_op(t_proc *proc, t_op_arg args[3])
{
	t_proc	*new_proc;

	new_proc = process_create(proc->pc, proc);
	process_move(new_proc, (short)args[0].value % IDX_MOD);
}
