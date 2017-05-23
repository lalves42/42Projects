/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:05:02 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/07 09:47:06 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		comment_error(void)
{
	ft_printf("asm: Champion comment is too long (Max length %i)\n",
	COMMENT_LENGTH);
	return (0);
}

int		name_error(void)
{
	ft_printf("asm: Champion name is too long (Max length %i)\n",
	PROG_NAME_LENGTH);
	return (0);
}

int		wrong_arg(char *opcode, char *arg)
{
	ft_printf("asm: Opcode '%s' has wrong(s) arg(s) '%s'\n", opcode, arg);
	return (0);
}

int		wrong_line(char *str)
{
	ft_printf("asm: Line '%s' is invalid\n", str);
	return (0);
}

int		error(char *str, int errno)
{
	char			*s;
	unsigned int	i;

	s = str;
	i = 0;
	while (*s++)
		i++;
	write(1, str, i);
	return (errno);
}
