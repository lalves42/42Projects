/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:38:23 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/17 16:27:14 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	get_input(int input, t_panel panels[3])
{
	if (input == 'n' || input == 's')
		g_corewar.state = STATE_STEP;
	else if (input == '+')
		wtimeout(panels[1].win, ++g_corewar.cycle_infos.speed);
	else if (input == '-')
		wtimeout(panels[1].win, --g_corewar.cycle_infos.speed);
	else if (input == ' ')
		g_corewar.state ^= STATE_RUNNING;
	else if (input == 'f')
	{
		g_corewar.flags ^= FLAG_FULL;
		panels_resize(panels);
	}
	else if (input == 'h')
	{
		g_corewar.flags ^= FLAG_HELP;
		panels_resize(panels);
	}
	else if (input == KEY_RESIZE)
		panels_resize(panels);
	else if (input == '\n')
		return (0);
	return (1);
}

void		curses_loop(int (*cycle_fn)(t_cycle_infos *))
{
	t_panel	panels[3];

	panels_init(panels);
	while (get_input(wgetch(panels[1].win), panels))
	{
		if (g_corewar.state & (STATE_RUNNING | STATE_STEP))
		{
			if (cycle_fn(&g_corewar.cycle_infos) <= 0)
			{
				g_corewar.state = STATE_DONE;
				g_corewar.flags &= ~FLAG_FULL;
				panels_resize(panels);
				timeout(-1);
				while (getch() == KEY_RESIZE)
					panels_resize(panels);
				break ;
			}
		}
		draw(panels, &g_corewar.cycle_infos);
	}
	window_destroy(panels[0].win);
	window_destroy(panels[1].win);
	window_destroy(panels[2].win);
	endwin();
}

void		curses_init(void)
{
	initscr();
	cbreak();
	raw();
	noecho();
	curs_set(0);
	start_color();
	load_player_colors();
	init_pair(PAIR_BORDER, COLOR_LIGHT_BLACK, COLOR_LIGHT_BLACK);
	init_pair(PAIR_GREY, COLOR_LIGHT_BLACK, COLOR_BLACK);
	init_memory(&g_corewar.cycle_infos);
}
