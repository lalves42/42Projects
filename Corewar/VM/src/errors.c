/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:30:12 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/12 19:03:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "corewar.h"

static void		usage(void)
{
	ft_eprintf(STR_USAGE,
			USAGE_DUMP,
			USAGE_CHAMP,
			OPTION_DUMP,
			OPTION_NUMBER,
			OPTION_HIDE,
			OPTION_CURSES);
	exit(ERRNO_USAGE);
}

void			error_max_size(char *path, int size)
{
	ft_eprintf("File %s %s (%i bytes > %i bytes)\n",
		path, ERR_CHAMP_FILE_TOO_BIG, size, CHAMP_MAX_SIZE);
	exit(ERRNO_CHAMP_FILE_TOO_BIG);
}

void			error(int errno, char *str)
{
	if (errno == ERRNO_USAGE)
		usage();
	ft_putstr_fd("Error: ", 2);
	if (errno == ERRNO_OPEN)
		ft_eprintf("%s '%s'\n", ERR_OPEN, str);
	else if (errno == ERRNO_EMPTY)
		ft_eprintf("File %s %s\n", str, ERR_EMPTY);
	else if (errno == ERRNO_HEADER)
		ft_eprintf("File %s %s\n", str, ERR_HEADER);
	else if (errno == ERRNO_CHAMP_FILE_TOO_SMALL)
		ft_eprintf("File %s %s\n", str, ERR_CHAMP_FILE_TOO_SMALL);
	else if (errno == ERRNO_PROG_SIZE)
		ft_eprintf("File %s %s\n", str, ERR_PROG_SIZE);
	else if (errno == ERRNO_CHAMP_NBR)
		ft_eprintf("%s\n", ERR_CHAMP_NBR);
	else if (errno == ERRNO_MEMORY)
		ft_eprintf(ERR_MEMORY, str, 2);
	else
		ft_putendl_fd(ERR_UNDEFINED, 2);
	exit(errno);
}
