/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:55:12 by lalves            #+#    #+#             */
/*   Updated: 2017/03/07 08:56:22 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"

t_op_check		*get_op_list(int i)
{
	static t_op_check	op_list[17] = {
	{ "live", &check_live },
	{ "ld", &check_ld },
	{ "st", &check_st },
	{ "add", &check_add },
	{ "sub", &check_sub },
	{ "and", &check_and },
	{ "or", &check_or },
	{ "xor", &check_xor },
	{ "zjmp", &check_zjmp },
	{ "ldi", &check_ldi },
	{ "sti", &check_sti },
	{ "fork", &check_fork },
	{ "lld", &check_lld },
	{ "lldi", &check_lldi },
	{ "lfork", &check_lfork },
	{ "aff", &check_aff },
	{ NULL, NULL }
	};

	return (&op_list[i]);
}

static void		check_args(char *line, t_env *env)
{
	int			i;
	char		**tab;
	t_op_check	*op_list;

	i = 0;
	tab = split_line(line);
	if (!tab)
		exit(wrong_line(line));
	while ((op_list = get_op_list(i)) && op_list->name)
	{
		if (!ft_strcmp(tab[0], op_list->name))
		{
			i = op_list->fn(tab[1], env);
			break ;
		}
		i++;
	}
	if (i == 0)
		exit(wrong_arg(tab[0], tab[1]));
	ft_strdel(&(tab[0]));
	ft_strdel(&(tab[1]));
	free(tab);
}

void			check_opcode(char *line, t_env *env)
{
	char	*s;
	size_t	i;

	s = ft_strtrim(line);
	i = 0;
	while (s[i])
	{
		if (!ft_isalpha(s[i]))
			break ;
		i++;
	}
	while (ft_isspace(s[i]))
		i++;
	check_args(line, env);
	ft_strdel(&s);
	(env->opcode)++;
}

static int		check_length(char *s, int i)
{
	if (i == 1)
		s += ft_strlen(NAME_CMD_STRING);
	else
		s += ft_strlen(COMMENT_CMD_STRING);
	while (ft_isspace(*s))
		s++;
	if (i == 1 && ft_strchr(&(s[1]), '"') - s - 2 > PROG_NAME_LENGTH)
		return (0);
	if (i == 1 && (ft_strchr(&(s[1]), '"') - s - 2 > COMMENT_LENGTH))
		return (0);
	return (1);
}

void			check_cmd_length(int fd)
{
	char	*line;
	char	*s;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		s = ft_strtrim(line);
		if (ft_strcmp(s, ""))
		{
			if (type_of_line(s) == 1 && !check_length(s, 1))
				exit(name_error());
			if (type_of_line(s) == 2 && !check_length(s, 2))
				exit(comment_error());
		}
		ft_strdel(&s);
		ft_strdel(&line);
	}
	lseek(fd, 0, SEEK_SET);
}
