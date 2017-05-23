/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:35:28 by lalves            #+#    #+#             */
/*   Updated: 2017/02/03 18:37:13 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static char		*new_room(t_env *data, char **str)
{
	t_room *new;

	new = (t_room*)malloc(sizeof(t_room));
	if (!new)
		ft_error("malloc");
	new->name = *str;
	new->weight = 0;
	new->link = NULL;
	new->next = data->rooms;
	data->rooms = new;
	(data->nb_room)++;
	return (new->name);
}

static int		check_room_name(t_env *data, char *str)
{
	t_room *ptr;

	if (!(data->rooms))
		return (1);
	ptr = data->rooms;
	while (ptr)
	{
		if (!ft_strcmp(ptr->name, str))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static int		check_coord(char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ')
		i++;
	i++;
	while (line[i])
	{
		if (line[i] != ' ' && !ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		count_space(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	if (count == 2 && line[0] != ' ' && line[i - 1] != ' ')
		return (1);
	return (0);
}

int				check_room(char *line, t_env *data, int cmd)
{
	int		i;
	char	*str;

	i = 0;
	if (data->nb_link)
		return (0);
	if (!count_space(line))
		return (0);
	if (!check_coord(line))
		return (0);
	while (line[i] != ' ')
		i++;
	str = ft_strsub(line, 0, i);
	if (!check_room_name(data, str))
	{
		ft_strdel(&str);
		return (0);
	}
	if (cmd == 1)
		data->start = ft_strdup(new_room(data, &str));
	else if (cmd == 2)
		data->end = ft_strdup(new_room(data, &str));
	else
		new_room(data, &str);
	return (1);
}
