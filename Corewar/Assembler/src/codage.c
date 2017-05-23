/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:33:29 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 08:12:41 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		get_arg_type(char *arg, int x)
{
	int i;

	i = 0;
	while (x > 1)
	{
		while (arg[i])
		{
			if (arg[i] == SEPARATOR_CHAR)
			{
				i++;
				if (arg[i] == ' ')
					i++;
				break ;
			}
			i++;
		}
		x--;
	}
	if (arg[i] == 'r')
		return (REG_CODE);
	if (arg[i] == DIRECT_CHAR)
		return (DIR_CODE);
	return (IND_CODE);
}

static void		third_arg(int fd, char *arg, char c)
{
	int arg_type;

	arg_type = get_arg_type(arg, 3);
	if (arg_type == REG_CODE)
		c = c | 0b00000100;
	else if (arg_type == DIR_CODE)
		c = c | 0b00001000;
	else if (arg_type == IND_CODE)
		c = c | 0b00001100;
	write(fd, &c, 1);
}

static void		second_arg(int fd, char *arg, char c, int arg_nb)
{
	int arg_type;

	arg_type = get_arg_type(arg, 2);
	if (arg_type == REG_CODE)
		c = c | 0b00010000;
	else if (arg_type == DIR_CODE)
		c = c | 0b00100000;
	else if (arg_type == IND_CODE)
		c = c | 0b00110000;
	if (arg_nb > 2)
		third_arg(fd, arg, c);
	else
		write(fd, &c, 1);
}

static void		first_arg(int fd, char *arg, char c, int arg_nb)
{
	int arg_type;

	arg_type = get_arg_type(arg, 1);
	if (arg_type == REG_CODE)
		c = c | 0b01000000;
	else if (arg_type == DIR_CODE)
		c = c | 0b10000000;
	else if (arg_type == IND_CODE)
		c = c | 0b11000000;
	if (arg_nb > 1)
		second_arg(fd, arg, c, arg_nb);
	else
		write(fd, &c, 1);
}

void			write_ocp(int fd, char *arg, int arg_nb)
{
	char c;

	c = 0;
	first_arg(fd, arg, c, arg_nb);
}
