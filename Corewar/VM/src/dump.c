/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:16:22 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/17 20:28:53 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		dump_memory(char *memory)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < MEM_SIZE)
	{
		if (j == 64)
		{
			ft_printf("\n");
			j = 0;
			k++;
		}
		if (j == 0)
			ft_printf("%#.4p : ", k * 64);
		ft_printf("%.2x ", memory[i] & 0xff);
		i++;
		j++;
	}
	ft_printf("\n");
	exit(0);
}
