/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:33:28 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/23 14:27:19 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	load_player_colors(void)
{
	static int	pairs[8][2] = {
		{ COLOR_GREEN, COLOR_BLACK },
		{ COLOR_RED, COLOR_BLACK },
		{ COLOR_YELLOW, COLOR_BLACK },
		{ COLOR_CYAN, COLOR_BLACK },
		{ COLOR_WHITE, COLOR_GREEN },
		{ COLOR_WHITE, COLOR_RED },
		{ COLOR_WHITE, COLOR_YELLOW },
		{ COLOR_WHITE, COLOR_CYAN }
	};
	int			i;

	i = 0;
	while (i < 4)
	{
		init_pair(i + 1, pairs[i][0], pairs[i][1]);
		init_pair(i + 5, pairs[i + 4][0], pairs[i + 4][1]);
		i++;
	}
}
