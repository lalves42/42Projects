/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:55:12 by lalves            #+#    #+#             */
/*   Updated: 2017/03/16 18:03:41 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "get_next_line.h"

char		**get_op_tab(int i)
{
	static char	*op_tab[17] = {
	"live",
	"ld",
	"st",
	"add",
	"sub",
	"and",
	"or",
	"xor",
	"zjmp",
	"ldi",
	"sti",
	"fork",
	"lld",
	"lldi",
	"lfork",
	"aff",
	NULL
	};

	return (&op_tab[i]);
}

static void	check_name(char *line, int *name)
{
	char	*s;
	char	*tmp;

	s = ft_strtrim(line);
	if (s[0] != '"' || (tmp = ft_strchr(&(s[1]), '"')) == NULL)
		exit(NAME_SYNTAX);
	tmp++;
	while (ft_isspace(*tmp))
		tmp++;
	if (*tmp && *tmp != COMMENT_CHAR && *tmp != ';')
		exit(wrong_line(s));
	(*name)++;
	ft_strdel(&s);
}

static void	check_com(char *line, int *comment)
{
	char	*s;
	char	*tmp;

	s = ft_strtrim(line);
	if (s[0] != '"' || (tmp = ft_strchr(&(s[1]), '"')) == NULL)
		exit(COMMENT_SYNTAX);
	tmp++;
	while (ft_isspace(*tmp))
		tmp++;
	if (*tmp && *tmp != COMMENT_CHAR && *tmp != ';')
		exit(wrong_line(s));
	(*comment)++;
	ft_strdel(&s);
}

static void	check_invalid_line(char *line, int type, t_env *env)
{
	if (type > 2 && !(env->name))
		exit(ERROR_NAME);
	if (type > 2 && !(env->comment))
		exit(ERROR_COMMENT);
	if (type == 4)
	{
		line = save_label(line, env);
		while (line && ft_isspace(*line))
			line++;
		if (!line || *line == COMMENT_CHAR || *line == ';')
			return ;
		type = type_of_line(line);
	}
	if (type == 1)
		check_name(line + ft_strlen(NAME_CMD_STRING), &(env->name));
	if (type == 2)
		check_com(line + ft_strlen(COMMENT_CMD_STRING), &(env->comment));
	if (!type)
		exit(wrong_line(line));
	if (type == 3)
		check_opcode(line, env);
}

void		check_invalid_file(t_env *env)
{
	char	*line;
	char	*s;
	int		ret;

	while ((ret = get_next_line(env->src_fd, &line)) > 0)
	{
		s = ft_strtrim(line);
		if (s[0] != COMMENT_CHAR && s[0] != ';' && ft_strcmp(s, ""))
			check_invalid_line(s, type_of_line(s), env);
		ft_strdel(&line);
		ft_strdel(&s);
	}
	if (ret == -1)
		exit(ERROR_READ_SRC);
	if (env->name != 1)
		exit(ERROR_NAME);
	if (env->comment != 1)
		exit(ERROR_COMMENT);
	if (env->opcode < 1)
		exit(ERROR_NO_OPCODE);
	lseek(env->src_fd, 0, SEEK_SET);
}
