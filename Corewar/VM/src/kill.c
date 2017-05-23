/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:23:32 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/17 14:51:54 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	resize_array(t_proc *new, t_proc *old, size_t old_size)
{
	int		from;
	size_t	idx;
	size_t	i;

	i = 0;
	idx = 0;
	from = -1;
	while (i < old_size)
	{
		if (old[i].live)
		{
			old[i].live = 0;
			if (from < 0)
				from = i;
		}
		else if (from >= 0)
		{
			ft_memcpy(&new[idx], &old[from], sizeof(t_proc) * (i - from));
			idx += i - from;
			from = -1;
		}
		i++;
	}
	if (from >= 0)
		ft_memcpy(&new[idx], &old[from], sizeof(t_proc) * (i - from));
}

void		kill_processes(size_t count)
{
	t_proc	*old;

	old = g_corewar.process;
	if (!(g_corewar.process = (t_proc *)malloc(sizeof(t_proc) * count)))
		error(ERRNO_MEMORY, "process kill");
	resize_array(g_corewar.process, old, g_corewar.process_count);
	g_corewar.process_count = count;
	free(old);
}
