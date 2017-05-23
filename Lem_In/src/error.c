/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:43:27 by lalves            #+#    #+#             */
/*   Updated: 2017/02/06 14:59:33 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		clear_rooms(t_room *ptr)
{
	t_room	*tmp;
	int		i;

	i = 0;
	while (ptr)
	{
		if (ptr->name)
			ft_strdel(&(ptr->name));
		if (ptr->link)
		{
			while (ptr->link && ptr->link[i])
				i++;
			ft_memdel((void**)&(ptr->link[i]));
			ft_memdel((void**)&(ptr->link));
			i = 0;
		}
		tmp = ptr;
		ptr = ptr->next;
		ft_memdel((void**)&tmp);
	}
}

void			free_fn(t_env *data)
{
	if (data->rooms)
		clear_rooms(data->rooms);
	if (data->start)
		ft_strdel(&(data->start));
	if (data->end)
		ft_strdel(&(data->end));
	ft_memdel((void**)&data);
}

void			parsing_error(t_env *data, char *line)
{
	if (data->rooms)
		clear_rooms(data->rooms);
	if (data->start)
		ft_strdel(&(data->start));
	if (data->end)
		ft_strdel(&(data->end));
	ft_memdel((void**)&data);
	if (line)
	{
		ft_putcolor(line, "red");
		ft_putchar('\n');
		ft_strdel(&line);
	}
	ft_putcolor("\nERROR\n", "red");
	exit(EXIT_FAILURE);
}
