/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 20:55:42 by lalves            #+#    #+#             */
/*   Updated: 2017/02/06 15:12:15 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static t_room	**realloc_link(t_room *src)
{
	t_room	**new;
	int		i;

	i = 0;
	while (src->link[i])
		i++;
	new = (t_room**)malloc(sizeof(t_room*) * (i + 2));
	if (!new)
		ft_error("malloc");
	i = 0;
	while (src->link[i])
	{
		new[i + 1] = src->link[i];
		i++;
	}
	new[i + 1] = NULL;
	new[0] = NULL;
	ft_memdel((void**)&src->link);
	return (new);
}

static t_room	**init_link(void)
{
	t_room **new;

	new = (t_room**)malloc(sizeof(t_room*) * 2);
	if (!new)
		ft_error("malloc");
	new[1] = NULL;
	new[0] = NULL;
	return (new);
}

static void		create_link(t_room *src, t_room *dst)
{
	if (!(src->link))
		src->link = init_link();
	else
		src->link = realloc_link(src);
	src->link[0] = dst;
}

static int		link_exist(t_room *first, t_room *second)
{
	t_room	**ptr;
	int		i;

	ptr = first->link;
	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		if (ptr[i] == second)
			return (1);
		i++;
	}
	return (0);
}

int				save_link(t_room *first, t_room *second, t_env *data)
{
	if (link_exist(first, second))
		return (1);
	create_link(first, second);
	create_link(second, first);
	(data->nb_link)++;
	return (1);
}
