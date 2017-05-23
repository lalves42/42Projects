/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:16:47 by lalves            #+#    #+#             */
/*   Updated: 2017/03/11 15:37:46 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_empty_file(int fd)
{
	off_t cur;

	cur = lseek(fd, 0, SEEK_CUR);
	if (lseek(fd, 0, SEEK_END) == cur)
		exit(ERROR_EMPTY_FILE);
	lseek(fd, cur, SEEK_SET);
}

static int	label_exist(char *line, size_t i, t_label *lst)
{
	line = ft_strsub(line, 0, i);
	while (lst)
	{
		if (!ft_strcmp(line, lst->label))
		{
			ft_strdel(&line);
			return (1);
		}
		lst = lst->next;
	}
	ft_strdel(&line);
	return (0);
}

static int	is_label(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == LABEL_CHAR)
			return (4);
		if (!ft_strchr(LABEL_CHARS, line[i]))
			return (0);
		i++;
	}
	return (0);
}

int			type_of_line(char *line)
{
	int		i;
	size_t	name;
	size_t	com;
	char	**op_tab;

	i = 0;
	name = ft_strlen(NAME_CMD_STRING);
	com = ft_strlen(COMMENT_CMD_STRING);
	if (!ft_strncmp(line, NAME_CMD_STRING, name) && ft_isspace(line[name]))
		return (1);
	if (!ft_strncmp(line, COMMENT_CMD_STRING, com) && ft_isspace(line[com]))
		return (2);
	while ((op_tab = get_op_tab(i)) && *op_tab)
	{
		if (!ft_strncmp(line, *op_tab, ft_strlen(*op_tab)))
		{
			if (ft_isspace(line[ft_strlen(*op_tab)]))
				return (3);
		}
		i++;
	}
	return (is_label(line));
}

char		*save_label(char *line, t_env *env)
{
	size_t	i;
	t_label	*new;

	i = 0;
	while (line[i] != LABEL_CHAR)
		i++;
	if (!label_exist(line, i, env->declare))
	{
		new = init_label(line, i);
		new->next = env->declare;
		env->declare = new;
	}
	if (line[i + 1])
		return (&(line[i + 1]));
	return (NULL);
}
