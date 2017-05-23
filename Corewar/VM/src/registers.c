/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:14:49 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/16 18:20:53 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** 1 < idx < REG_NUMBER
*/

t_reg		*get_register(t_reg *registers, int idx)
{
	if (idx < 1 || idx > REG_NUMBER)
	{
		g_corewar.reg_error = 1;
		return (NULL);
	}
	return (&registers[idx - 1]);
}

void		read_register(t_reg reg[REG_SIZE], char *value)
{
	if (reg)
		swap_endianess(value, (char *)reg, REG_SIZE);
}

void		store_register(t_reg reg[REG_SIZE], char *value)
{
	if (reg)
		swap_endianess((char *)reg, value, REG_SIZE);
}

void		write_register(t_reg reg[REG_SIZE], char *pc, int champ_number)
{
	if (reg)
		write_range((char *)reg, pc, REG_SIZE, champ_number);
}

void		copy_register(t_reg r1[REG_SIZE], t_reg r2[REG_SIZE])
{
	if (r1 && r2)
		ft_memcpy((void *)r1, (void *)r2, REG_SIZE);
}
