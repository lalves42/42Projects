/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:23:18 by akopera           #+#    #+#             */
/*   Updated: 2017/03/15 01:40:16 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st_op(t_proc *proc, t_op_arg args[3])
{
	int	champ_number;

	if (args[1].type == T_IND)
	{
		champ_number = 0;
		read_register(get_register(proc->reg, 1), (char *)&champ_number);
		write_register(get_register(proc->reg, args[0].value),
					proc->pc + ((short)args[1].value) % IDX_MOD, champ_number);
	}
	else if (args[1].type == T_REG)
		copy_register(get_register(proc->reg, args[1].value),
						get_register(proc->reg, args[0].value));
}
