/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 21:27:30 by lalves            #+#    #+#             */
/*   Updated: 2017/03/11 17:05:16 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			save_label_data(t_label *lst, int type, int modifier, int fd)
{
	lst->pos_to_write = lseek(fd, 0, SEEK_CUR);
	lst->done = 1;
	if (type == 1 && !modifier)
		lst->bytes = DIR_SIZE;
	else
		lst->bytes = IND_SIZE;
}

void			get_label_use_offset(char *arg, t_env *env)
{
	t_label *lst;
	size_t	i;

	lst = env->use;
	i = 0;
	arg = ft_strchr(arg, LABEL_CHAR);
	if (!arg)
		return ;
	arg++;
	while (arg[i] && ft_strchr(LABEL_CHARS, arg[i]))
		i++;
	arg = ft_strsub(arg, 0, i);
	while (lst)
	{
		if (!ft_strcmp(arg, lst->label) && !(lst->pos))
		{
			lst->pos = lseek(env->dst_fd, 0, SEEK_CUR);
			break ;
		}
		lst = lst->next;
	}
	ft_strdel(&arg);
}

static void		write_fn(int fd, off_t pos, int nb, int byte_to_write)
{
	char *number;

	number = (char*)&nb;
	lseek(fd, pos, SEEK_SET);
	while (byte_to_write >= 0)
	{
		write(fd, number + byte_to_write, 1);
		byte_to_write--;
	}
}

void			write_labels(t_env *env)
{
	t_label *d;
	t_label *u;
	int		nb;

	d = env->declare;
	u = env->use;
	while (u)
	{
		while (d)
		{
			if (!ft_strcmp(d->label, u->label))
			{
				nb = d->pos - u->pos;
				write_fn(env->dst_fd, u->pos_to_write, nb, u->bytes - 1);
				d = env->declare;
				break ;
			}
			d = d->next;
		}
		u = u->next;
	}
}
