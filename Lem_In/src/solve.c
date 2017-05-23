/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:05:17 by lalves            #+#    #+#             */
/*   Updated: 2017/02/06 15:08:05 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static t_path	*init_path(t_room *ptr, t_env *data)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(t_path));
	if (!new)
		ft_error("malloc");
	new->room = ptr;
	if (!ft_strcmp(ptr->name, data->end))
		new->cur_ant = -42;
	else
		new->cur_ant = 0;
	new->gone_ant = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void		new_node(t_path *path, t_env *data, t_room *ptr)
{
	t_path *new;

	new = init_path(ptr, data);
	while (path->next)
		path = path->next;
	path->next = new;
	new->prev = path;
}

static t_room	*get_start(t_env *data)
{
	t_room *ptr;

	ptr = data->rooms;
	while (ptr->next)
	{
		if (!ft_strcmp(ptr->name, data->start))
			break ;
		ptr = ptr->next;
	}
	return (ptr);
}

int				solve(t_env *data)
{
	t_path	*begin;
	t_room	*ptr;
	int		i;

	ptr = get_start(data);
	begin = init_path(ptr, data);
	while (ft_strcmp(ptr->name, data->end))
	{
		i = 0;
		while (ptr->link && ptr->link[i])
		{
			if (ptr->link[i]->weight == ptr->weight - 1)
			{
				new_node(begin, data, ptr->link[i]);
				ptr = ptr->link[i];
				break ;
			}
			i++;
		}
	}
	print_solve(begin, data);
	return (0);
}
