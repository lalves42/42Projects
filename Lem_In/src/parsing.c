/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:31:41 by lalves            #+#    #+#             */
/*   Updated: 2017/02/06 15:18:45 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int		complete_path(t_env *data)
{
	int		i;
	t_room	*ptr;

	i = 0;
	ptr = data->rooms;
	while (ptr->next)
	{
		if (!ft_strcmp(ptr->name, data->start))
			break ;
		ptr = ptr->next;
	}
	while (ptr->link && ptr->link[i])
	{
		if (ptr->link[i]->weight)
		{
			ptr->weight = ptr->link[i]->weight + 1;
			return (1);
		}
		i++;
	}
	return (0);
}

static int		check_path(t_env *data, int step)
{
	int		i;
	t_room	*ptr;

	i = 0;
	ptr = data->rooms;
	if (step > data->nb_room)
		return (0);
	while (ptr)
	{
		if (ptr->weight == step - 1)
		{
			while (ptr->link && ptr->link[i])
			{
				if (!(ptr->link[i]->weight))
					ptr->link[i]->weight = step;
				i++;
			}
			i = 0;
		}
		ptr = ptr->next;
	}
	if (complete_path(data))
		return (1);
	return (check_path(data, step + 1));
}

static int		can_start(t_env *data)
{
	t_room	*ptr;
	int		i;

	if (!(data->start) || !(data->end) || !(data->nb_link))
		return (0);
	ptr = data->rooms;
	while (ptr && ft_strcmp(ptr->name, data->end))
		ptr = ptr->next;
	ptr->weight = 1;
	i = check_path(data, 2);
	return (i);
}

static void		get_ants(t_env *data, char *line)
{
	int		i;

	i = 0;
	if (get_next_line(0, &line) == -1)
		ft_error("read");
	if (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			parsing_error(data, line);
	}
	else
	{
		while (line[i])
		{
			if (!ft_isdigit(line[i]))
				parsing_error(data, line);
			i++;
		}
		data->ants = ft_atoi(line);
		if (!data->ants)
			parsing_error(data, line);
	}
	ft_putendl(line);
	ft_strdel(&line);
}

int				parsing(t_env *data)
{
	char	*line;
	int		ret;

	line = NULL;
	while (!(data->ants))
		get_ants(data, line);
	while ((ret = get_next_line(0, &line)))
	{
		if (!check_line(&line, data))
		{
			if (!can_start(data))
				parsing_error(data, line);
			ft_strdel(&line);
			ft_putchar('\n');
			return (solve(data));
		}
		ft_putendl(line);
		ft_strdel(&line);
	}
	if (ret == -1)
		ft_error("read");
	ft_putchar('\n');
	if (!can_start(data))
		parsing_error(data, line);
	return (solve(data));
}
