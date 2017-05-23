/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 19:05:42 by tdefresn          #+#    #+#             */
/*   Updated: 2017/03/07 08:04:59 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

void			write_prog_size(int fd)
{
	off_t	cur;
	off_t	end;
	int		size[1];

	cur = lseek(fd, 0, SEEK_CUR);
	end = lseek(fd, 0, SEEK_END);
	size[0] = end - lseek(fd, sizeof(t_header), SEEK_SET);
	lseek(fd, 8 + PROG_NAME_LENGTH, SEEK_SET);
	write(fd, (char*)size + 3, 1);
	write(fd, (char*)size + 2, 1);
	write(fd, (char*)size + 1, 1);
	write(fd, (char*)size, 1);
	lseek(fd, cur, SEEK_SET);
}

void			write_arg(int fd, int *nb, int byte_to_write)
{
	while (byte_to_write >= 0)
	{
		write(fd, ((char*)nb) + byte_to_write, 1);
		byte_to_write--;
	}
}

static void		push_next_arg(char **arg)
{
	int i;

	i = 0;
	while ((*arg)[i])
	{
		if ((*arg)[i] == COMMENT_CHAR || (*arg)[i] == ';')
		{
			*arg = ft_strchr(*arg, 0);
			return ;
		}
		if ((*arg)[i] == SEPARATOR_CHAR)
		{
			i++;
			if ((*arg)[i] == ' ')
				i++;
			*arg = &((*arg)[i]);
			return ;
		}
		i++;
	}
	*arg = &((*arg)[i]);
}

int				save_used_label(char *arg, t_env *env, int type, int modifier)
{
	t_label *lst;
	size_t	i;

	i = 0;
	lst = env->use;
	if (*arg == DIRECT_CHAR)
		arg++;
	if (*arg == LABEL_CHAR)
		arg++;
	while (arg[i] && arg[i] != SEPARATOR_CHAR && !ft_isspace(arg[i])
		&& arg[i] != ';')
		i++;
	arg = ft_strsub(arg, 0, i);
	while (lst)
	{
		if (!ft_strcmp(arg, lst->label) && lst->done == 0 && lst->pos)
		{
			save_label_data(lst, type, modifier, env->dst_fd);
			break ;
		}
		lst = lst->next;
	}
	ft_strdel(&arg);
	return (0);
}

int				get_arg(char **arg, int *nb, t_env *env, int modifier)
{
	if ((*arg)[0] == 'r')
	{
		*nb = ft_atoi((*arg) + 1);
		push_next_arg(arg);
		return (1);
	}
	else if ((*arg)[0] == DIRECT_CHAR)
	{
		if ((*arg)[1] == LABEL_CHAR)
			*nb = save_used_label(*arg, env, 1, modifier);
		else
			*nb = ft_atoi((*arg) + 1);
		push_next_arg(arg);
		return (DIR_SIZE);
	}
	else
	{
		if ((*arg)[0] == LABEL_CHAR)
			*nb = save_used_label(*arg, env, 0, modifier);
		else
			*nb = ft_atoi(*arg);
		push_next_arg(arg);
		return (IND_SIZE);
	}
}
