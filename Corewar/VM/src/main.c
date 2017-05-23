/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:27:30 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/18 13:15:36 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_corewar	g_corewar;

int		main(int ac, char **av)
{
	if (ac < 2)
		error(ERRNO_USAGE, NULL);
	ft_bzero(&g_corewar, sizeof(t_corewar));
	g_corewar.dump_cycle = -1;
	parse_arguments(ac - 1, &av[1], &g_corewar.flags);
	run_vm();
	return (0);
}
