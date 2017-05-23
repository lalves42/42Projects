/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:49:09 by lalves            #+#    #+#             */
/*   Updated: 2017/03/11 17:28:47 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

char		*convert_path(char *path)
{
	char	*new_path;
	size_t	len;

	len = ft_strlen(path);
	new_path = ft_strnew(len + 2);
	new_path = ft_strcpy(new_path, path);
	new_path[len - 1] = 'c';
	new_path[len] = 'o';
	new_path[len + 1] = 'r';
	new_path[len + 2] = '\0';
	return (new_path);
}

t_label		*init_label(char *line, size_t i)
{
	t_label *new;

	new = malloc(sizeof(t_label));
	if (!new)
		exit(ERROR_MALLOC);
	new->label = ft_strsub(line, 0, i);
	new->pos = 0;
	new->pos_to_write = 0;
	new->done = 0;
	new->bytes = 0;
	new->next = NULL;
	return (new);
}

void		parse_helper(char **line, t_env *env)
{
	get_label_declare_offset(*line, env);
	free(*line);
}

t_env		*init_env(char *src_path)
{
	t_env *new;

	new = malloc(sizeof(t_env));
	if (!new)
		exit(ERROR_MALLOC);
	new->declare = NULL;
	new->use = NULL;
	if ((new->src_fd = open(src_path, O_RDONLY)) < 0)
		exit(ERROR_OPEN_SRC);
	new->dst_fd = 0;
	new->name = 0;
	new->comment = 0;
	new->opcode = 0;
	return (new);
}

void		clear_env(t_env **env)
{
	t_label *tmp;
	t_label *lst;

	close((*env)->src_fd);
	close((*env)->dst_fd);
	lst = (*env)->declare;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->label);
		free(tmp);
	}
	lst = (*env)->use;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->label);
		free(tmp);
	}
	free(*env);
}
