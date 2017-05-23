/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:39:58 by lalves            #+#    #+#             */
/*   Updated: 2017/02/25 16:21:19 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_or(char *arg, t_env *env)
{
	if (!check_dir(arg, env) && !check_ind(arg, env) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, env) && !check_ind(arg, env) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_xor(char *arg, t_env *env)
{
	if (!check_dir(arg, env) && !check_ind(arg, env) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, env) && !check_ind(arg, env) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_zjmp(char *arg, t_env *env)
{
	if (!check_dir(arg, env))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_ldi(char *arg, t_env *env)
{
	if (!check_dir(arg, env) && !check_ind(arg, env) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, env) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}

int		check_sti(char *arg, t_env *env)
{
	if (!check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, env) && !check_ind(arg, env) && !check_reg(arg))
		return (0);
	arg = next_arg(arg);
	if (!check_dir(arg, env) && !check_reg(arg))
		return (0);
	arg = next_arg(arg) - 1;
	if (*arg == SEPARATOR_CHAR)
		return (0);
	return (1);
}
