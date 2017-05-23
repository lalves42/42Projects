/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:04:02 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/17 16:37:52 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	draw(t_panel panels[3], t_cycle_infos *infos)
{
	mark_bytes(&g_corewar.cycle_infos);
	panel_memory_draw(&panels[0], infos);
	wrefresh(panels[0].win);
	if (!(g_corewar.flags & FLAG_FULL))
	{
		panel_infos_draw(&panels[1]);
		wrefresh(panels[1].win);
		if (!(g_corewar.flags & FLAG_HELP))
		{
			panel_help_draw(&panels[2]);
			wrefresh(panels[2].win);
		}
	}
	if (!(g_corewar.state & STATE_RUNNING))
		g_corewar.state = STATE_PAUSED;
}
