/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:20:52 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/12 18:50:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_dump(char *arg, t_flags *flags)
{
	if (!ft_isdigit(arg[0]))
		error(ERRNO_USAGE, NULL);
	g_corewar.dump_cycle = ft_atoi(arg);
	*flags &= ~FLAG_DUMP;
}

static void	set_champ_num(char **argv, int n, char *arg, t_flags *flags)
{
	if (!ft_isdigit(arg[0]))
		error(ERRNO_USAGE, NULL);
	read_champion(argv[n + 1], ft_atoi(argv[n]));
	*flags &= ~FLAG_NUMB;
}

void		parse_arguments(int argc, char **argv, t_flags *flags)
{
	char		*arg;
	int			i;

	i = 0;
	*flags = FLAG_NONE;
	while (i < argc)
	{
		arg = argv[i];
		if (arg[0] == '-')
			match_options(arg, flags);
		else if (*flags & FLAG_DUMP)
			set_dump(arg, flags);
		else if (*flags & FLAG_NUMB)
			set_champ_num(argv, i++, arg, flags);
		else
			read_champion(arg, -1);
		if (*flags & FLAG_DUMP && *flags & FLAG_NUMB)
			error(ERRNO_USAGE, NULL);
		i++;
	}
	if (*flags & FLAG_NCUR)
		g_corewar.dump_cycle = -1;
}
