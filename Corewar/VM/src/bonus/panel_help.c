/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:45:44 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/12 20:25:31 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	print_commands(WINDOW *win, t_vec2 *pos, t_vec2 *max)
{
	char	buf[64];

	pos->y++;
	ft_snprintf(buf, 64, STR_COMMAND_HELP);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_COMMAND_FULL);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_COMMAND_NEXT);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_COMMAND_PAUSE);
	wprint_buf(win, pos, max, buf);
	ft_snprintf(buf, 64, STR_COMMAND_END);
	wprint_buf(win, pos, max, buf);
}

void		panel_help_draw(t_panel *panel)
{
	char		buf[64];
	t_vec2		max;
	t_vec2		pos;

	pos.y = 2;
	pos.x = 3;
	max.y = panel->size.y - 2;
	wattron(panel->win, A_BOLD);
	ft_snprintf(buf, 64, STR_HELP);
	max.x = panel->size.x - 5;
	wprint_buf(panel->win, &pos, &max, buf);
	print_commands(panel->win, &pos, &max);
	wattroff(panel->win, A_BOLD);
}
