/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:34:51 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/18 12:27:35 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "bonus/bonus.h"

static void	get_live_die_count(size_t *live_count, size_t *die_count)
{
	int			i;

	*live_count = 0;
	*die_count = 0;
	i = g_corewar.process_count;
	while (--i >= 0)
	{
		if (g_corewar.process[i].live)
			*live_count += g_corewar.process[i].live;
		else
			(*die_count)++;
	}
}

static int	check_process_live_msg(void)
{
	size_t		live_count;
	size_t		die_count;
	int			i;

	get_live_die_count(&live_count, &die_count);
	if (die_count > 0)
		kill_processes(g_corewar.process_count - die_count);
	else
	{
		i = g_corewar.process_count;
		while (--i >= 0)
			g_corewar.process[i].live = 0;
	}
	i = g_corewar.player_count;
	while (--i >= 0)
		g_corewar.players[i].current_lives = 0;
	return (live_count >= NBR_LIVE);
}

static int	cycle(t_cycle_infos *infos)
{
	if (infos->count >= (unsigned int)g_corewar.dump_cycle)
		dump_memory(infos->arena);
	infos->count++;
	run_processes();
	if (infos->count >= infos->check_cycle)
	{
		infos->checks_count += (check_process_live_msg()) ? MAX_CHECKS : 1;
		infos->check_cycle = infos->count + infos->cycle_to_die;
	}
	if (infos->checks_count >= MAX_CHECKS)
	{
		infos->checks_count = 0;
		infos->cycle_to_die -= CYCLE_DELTA;
		infos->check_cycle -= CYCLE_DELTA;
	}
	if (g_corewar.process_count <= 0 || infos->cycle_to_die <= 0)
		return (0);
	return (1);
}

#ifdef BONUS

void		cycle_handler(void)
{
	if (g_corewar.flags & FLAG_NCUR)
	{
		curses_init();
		curses_loop(&cycle);
	}
	else
	{
		while (cycle(&g_corewar.cycle_infos))
			;
	}
}

#else

void		cycle_handler(void)
{
	while (cycle(&g_corewar.cycle_infos))
		;
}

#endif
