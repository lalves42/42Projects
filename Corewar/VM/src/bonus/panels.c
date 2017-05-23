/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:21:04 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/17 16:16:02 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void		panel_help_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = size.y - PANEL_HELP_HEIGHT;
	pos.x = size.x - (size.x * WIN_RATIO) - 1;
	size.y = PANEL_HELP_HEIGHT;
	if (size.y > LINES)
		size.y = LINES;
	if (!(g_corewar.flags & FLAG_FULL))
		size.x = size.x - pos.x;
	else
	{
		size.y = 0;
		size.x = 0;
		pos.x = 0;
		pos.y = 0;
	}
	panel->size.y = size.y;
	panel->size.x = size.x;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
}

static void		panel_infos_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = size.x - (size.x * WIN_RATIO) - 1;
	if (!(g_corewar.flags & FLAG_HELP))
		size.y -= PANEL_HELP_HEIGHT - 1;
	if (size.y < 0)
		size.y = 0;
	if (!(g_corewar.flags & FLAG_FULL))
		size.x = size.x - pos.x;
	else
	{
		size.y = 0;
		size.x = 0;
		pos.x = 0;
		pos.y = 0;
	}
	panel->size.y = size.y;
	panel->size.x = size.x;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
	wtimeout(panel->win, g_corewar.cycle_infos.speed);
}

static void		panel_memory_init(t_panel *panel, t_vec2 size)
{
	t_vec2	pos;

	pos.y = 0;
	pos.x = 0;
	if (!(g_corewar.flags & FLAG_FULL))
		size.x -= size.x * WIN_RATIO;
	panel->size.y = size.y;
	panel->size.x = size.x;
	panel->win = newwin(size.y, size.x, pos.y, pos.x);
	wattron(panel->win, COLOR_PAIR(PAIR_BORDER));
	wborder(panel->win, '*', '*', '*', '*', '*', '*', '*', '*');
	wattroff(panel->win, COLOR_PAIR(PAIR_BORDER));
}

void			panels_resize(t_panel panels[3])
{
	window_destroy(panels[0].win);
	window_destroy(panels[1].win);
	window_destroy(panels[2].win);
	panels_init(panels);
}

void			panels_init(t_panel panels[3])
{
	t_vec2	size;

	getmaxyx(stdscr, size.y, size.x);
	panel_memory_init(&panels[0], size);
	panel_infos_init(&panels[1], size);
	panel_help_init(&panels[2], size);
	refresh();
	draw(panels, &g_corewar.cycle_infos);
}
