/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:29:50 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/16 18:12:12 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	match_short(const t_option *options, char *arg, t_flags *flags)
{
	t_option	opt;
	int			len;
	int			i;
	int			j;

	i = 0;
	len = (int)ft_strlen(arg);
	while (i < len)
	{
		j = 0;
		while (j < OPTIONS_COUNT)
		{
			opt = options[j];
			if (arg[i] == opt.s)
			{
				*flags |= opt.f;
				break ;
			}
			j++;
		}
		if (j >= OPTIONS_COUNT)
			error(ERRNO_USAGE, NULL);
		i++;
	}
}

static void	match_long(const t_option *options, char *arg, t_flags *flags)
{
	t_option	opt;
	int			i;

	i = 0;
	while (i < OPTIONS_COUNT)
	{
		opt = options[i];
		if (ft_strequ(arg, opt.l))
		{
			*flags |= opt.f;
			break ;
		}
		i++;
	}
	if (i >= OPTIONS_COUNT)
		error(ERRNO_USAGE, NULL);
}

void		match_options(char *arg, t_flags *flags)
{
	static const t_option	options[OPTIONS_COUNT] = {
		{ .s = 'd', .l = "dump", .f = FLAG_DUMP },
		{ .s = 'h', .l = "hide", .f = FLAG_HIDE },
		{ .s = 'v', .l = "verbose", .f = FLAG_VERB },
		{ .s = 'n', .l = "number", .f = FLAG_NUMB },
		{ .s = 'c', .l = "ncurses", .f = FLAG_NCUR }
	};

	if (*flags & FLAG_DUMP || *flags & FLAG_NUMB)
		error(ERRNO_USAGE, NULL);
	*flags &= ~FLAG_DUMP;
	*flags &= ~FLAG_NUMB;
	if (arg[1] == '-')
		match_long(options, &arg[2], flags);
	else
		match_short(options, &arg[1], flags);
}
