/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/02/22 18:30:02 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

int			zjmp_fn(t_env *env, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	get_label_use_offset(arg, env);
	write(env->dst_fd, &opcode, 1);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb, env, 1);
		if (byte_to_write == DIR_SIZE)
			byte_to_write = IND_SIZE;
		write_arg(env->dst_fd, &nb, byte_to_write - 1);
	}
	return (1);
}

int			ldi_fn(t_env *env, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	get_label_use_offset(arg, env);
	write(env->dst_fd, &opcode, 1);
	write_ocp(env->dst_fd, arg, 3);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb, env, 1);
		if (byte_to_write == DIR_SIZE)
			byte_to_write = IND_SIZE;
		write_arg(env->dst_fd, &nb, byte_to_write - 1);
	}
	return (1);
}

int			sti_fn(t_env *env, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	get_label_use_offset(arg, env);
	write(env->dst_fd, &opcode, 1);
	write_ocp(env->dst_fd, arg, 3);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb, env, 1);
		if (byte_to_write == DIR_SIZE)
			byte_to_write = IND_SIZE;
		write_arg(env->dst_fd, &nb, byte_to_write - 1);
	}
	return (1);
}

int			fork_fn(t_env *env, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	get_label_use_offset(arg, env);
	write(env->dst_fd, &opcode, 1);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb, env, 1);
		if (byte_to_write == DIR_SIZE)
			byte_to_write = IND_SIZE;
		write_arg(env->dst_fd, &nb, byte_to_write - 1);
	}
	return (1);
}

int			lld_fn(t_env *env, char *arg, char opcode)
{
	int		nb;
	int		byte_to_write;

	get_label_use_offset(arg, env);
	write(env->dst_fd, &opcode, 1);
	write_ocp(env->dst_fd, arg, 2);
	while (*arg)
	{
		byte_to_write = get_arg(&arg, &nb, env, 0);
		write_arg(env->dst_fd, &nb, byte_to_write - 1);
	}
	return (1);
}
