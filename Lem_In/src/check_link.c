/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 20:21:22 by lalves            #+#    #+#             */
/*   Updated: 2017/02/06 14:59:02 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static size_t	check_rooms(char *name1, char *name2, t_env *data)
{
	t_room	*ptr;
	t_room	*i1;
	t_room	*i2;

	ptr = data->rooms;
	i1 = NULL;
	i2 = NULL;
	while (ptr)
	{
		if (!ft_strcmp(name1, ptr->name))
			i1 = ptr;
		if (!ft_strcmp(name2, ptr->name))
			i2 = ptr;
		ptr = ptr->next;
	}
	if (i1 && i2)
		return (save_link(i1, i2, data));
	return (0);
}

static int		get_names(char *line, int dash, t_env *data)
{
	int		len;
	char	*name1;
	char	*name2;
	t_room	*ptr;

	ptr = data->rooms;
	len = (int)ft_strlen(&(line[dash + 1]));
	name1 = ft_strsub(line, 0, dash);
	name2 = ft_strsub(line, dash + 1, len);
	if (!ft_strcmp(name1, name2))
	{
		ft_strdel(&name1);
		ft_strdel(&name2);
		return (0);
	}
	len = check_rooms(name1, name2, data);
	ft_strdel(&name1);
	ft_strdel(&name2);
	return (len);
}

static int		find_dash(char *line)
{
	int i;
	int count;
	int pos;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '-')
		{
			pos = i;
			count++;
		}
		i++;
	}
	if (count == 1 && pos && pos != (i - 1))
		return (pos);
	return (0);
}

int				check_link(char *line, t_env *data)
{
	int dash;

	if (!(data->nb_room))
		return (0);
	dash = find_dash(line);
	if (!dash)
		return (0);
	return (get_names(line, dash, data));
}
