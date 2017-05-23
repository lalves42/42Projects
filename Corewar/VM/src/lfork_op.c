/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:40 by akopera           #+#    #+#             */
/*   Updated: 2017/03/18 13:08:56 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lfork_op(t_proc *proc, t_op_arg args[3])
{
	t_proc	*new_proc;

	new_proc = process_create(proc->pc, proc);
	process_move(new_proc, (short)args[0].value);
}
