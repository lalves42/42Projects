/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:11:02 by lalves            #+#    #+#             */
/*   Updated: 2017/02/28 08:11:45 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	check_sharp(char **line, t_env *data)
{
	if (!ft_strcmp(*line, "##start"))
	{
		if (data->start)
			return (0);
		ft_putendl(*line);
		ft_strdel(line);
		if (!get_next_line(0, line))
			return (0);
		if (!check_room(*line, data, 1))
			return (0);
		return (1);
	}
	if (!ft_strcmp(*line, "##end"))
	{
		if (data->end)
			return (0);
		ft_putendl(*line);
		ft_strdel(line);
		if (!get_next_line(0, line))
			return (0);
		if (!check_room(*line, data, 2))
			return (0);
		return (1);
	}
	return (1);
}

int			check_line(char **line, t_env *data)
{
	int i;

	i = 0;
	if ((*line)[0] == '#')
		return (check_sharp(line, data));
	while ((*line)[i])
	{
		if ((*line)[i] == ' ')
			return (check_room(*line, data, 0));
		i++;
	}
	return (check_link(*line, data));
}
