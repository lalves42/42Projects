/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 23:54:47 by lalves            #+#    #+#             */
/*   Updated: 2017/03/11 15:24:41 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_find(t_data *data, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (data->str[i])
	{
		if (data->str[i] == '\n')
		{
			*line = ft_strsub(data->str, 0, i);
			if (data->str[i + 1])
			{
				tmp = data->str;
				data->str = &(data->str[i + 1]);
				data->rest = ft_strdup(data->str);
				ft_strdel(&tmp);
			}
			else
				ft_strdel(&(data->str));
			return (1);
		}
		i++;
	}
	data->rest = ft_strdup(data->str);
	ft_strdel(&(data->str));
	return (0);
}

int		ft_helper(t_data *data, char **line)
{
	data->str = ft_strdup(data->rest);
	ft_strdel(&(data->rest));
	if (ft_find(data, line) == 1)
		return (1);
	*line = ft_strdup(data->rest);
	ft_strdel(&(data->rest));
	return (1);
}

int		ft_read(t_data *data, const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];

	while ((data->ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[data->ret] = '\0';
		if (!(data->rest))
			data->rest = ft_strdup("");
		data->str = ft_strjoin(data->rest, buf);
		ft_strdel(&(data->rest));
		if (ft_find(data, line) == 1)
			return (1);
	}
	if (data->ret == -1)
	{
		if (data->rest)
			ft_strdel(&(data->rest));
		return (-1);
	}
	if (data->ret == 0 && data->rest)
		return (ft_helper(data, line));
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_data	*data[10];
	int				i;

	i = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while (data[i] && data[i]->cur_fd != fd)
		i++;
	if (!data[i])
	{
		data[i] = (t_data*)malloc(sizeof(t_data));
		if (!data[i])
			return (-1);
		data[i]->str = NULL;
		data[i]->rest = NULL;
		data[i]->ret = 0;
		data[i]->cur_fd = fd;
	}
	return (ft_read(data[i], fd, line));
}
