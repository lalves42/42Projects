/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:00:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/17 12:37:42 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_ocp(t_proc *proc, t_op_arg args[3])
{
	int		i;

	i = 0;
	while (i < proc->op->args_count)
	{
		if (!(args[i].type & proc->op->args_types[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	do_op(void (*op_fn)(t_proc *, t_op_arg[3]), t_proc *proc)
{
	t_op_arg	args[3];
	int			offset;

	proc->wait = -1;
	g_corewar.reg_error = 0;
	offset = get_argument_op(proc, proc->op->value, args);
	if (op_fn == &zjmp_op)
	{
		op_fn(proc, args);
		return (0);
	}
	if (!proc->op->ocp || check_ocp(proc, args))
		op_fn(proc, args);
	return (offset);
}

char		*process_move(t_proc *proc, int offset)
{
	char	*pc;
	char	*mem;

	proc->op = NULL;
	proc->wait = -1;
	pc = proc->pc + offset;
	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	proc->pc = pc;
	return (pc);
}

t_proc		*process_create(char *pc, t_proc *parent)
{
	static unsigned int	uid = 0;
	t_proc				*new_proc;
	t_proc				buf;
	int					count;

	if (parent)
		ft_memcpy(&buf, parent, sizeof(t_proc));
	g_corewar.process_count++;
	count = g_corewar.process_count;
	g_corewar.process = realloc(g_corewar.process, sizeof(t_proc) * count);
	if (!g_corewar.process)
		error(ERRNO_MEMORY, "process create");
	new_proc = &g_corewar.process[count - 1];
	ft_bzero(new_proc, sizeof(t_proc));
	new_proc->pc = pc;
	if (parent)
		ft_memcpy(new_proc, &buf, sizeof(t_proc));
	new_proc->id = uid++;
	new_proc->wait = -1;
	new_proc->op = NULL;
	return (new_proc);
}

int			process_op(t_proc *proc)
{
	static void	(*opcode_fns[OP_COUNT])(t_proc *, t_op_arg[3]) = {
		&live_op,
		&ld_op,
		&st_op,
		&add_op,
		&sub_op,
		&and_op,
		&or_op,
		&xor_op,
		&zjmp_op,
		&ldi_op,
		&sti_op,
		&fork_op,
		&lld_op,
		&lldi_op,
		&lfork_op,
		&aff_op
	};

	if (proc->op == NULL)
		return (1);
	return (do_op(opcode_fns[proc->op->value - 1], proc));
}
