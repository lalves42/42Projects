/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 08:19:14 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/28 18:54:44 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	wprint_buf(WINDOW *win, t_vec2 *pos, t_vec2 *max, char *buf)
{
	if (pos->y < max->y)
	{
		wmove(win, pos->y, pos->x);
		waddnstr(win, buf, max->x);
	}
	pos->y += 1;
}
