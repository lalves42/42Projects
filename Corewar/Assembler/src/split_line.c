/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:41:50 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 07:44:02 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	count_space(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == SEPARATOR_CHAR)
		{
			count += before_space(str, i - 1);
			count += after_space(str, i + 1);
		}
		i++;
	}
	return (count);
}

static int	next_char(char *str, int i)
{
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == SEPARATOR_CHAR)
		return (1);
	return (0);
}

static int	prev_char(char *str, int i)
{
	while (i >= 0 && ft_isspace(str[i]))
		i--;
	if (str[i] == SEPARATOR_CHAR)
		return (1);
	return (0);
}

static char	*get_args(char *str)
{
	char	*s;
	int		i;
	int		j;

	str = ft_strtrim(str);
	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (ft_strlen(str) - count_space(str)) + 1);
	while (str[i])
	{
		if (!ft_isspace(str[i]))
		{
			s[j] = str[i];
			j++;
		}
		else if (!next_char(str, i) && !prev_char(str, i))
		{
			s[j] = str[i];
			j++;
		}
		i++;
	}
	s[j] = str[i];
	ft_strdel(&str);
	return (s);
}

char		**split_line(char *str)
{
	size_t	i;
	char	**tab;

	i = 0;
	str = ft_strtrim(str);
	tab = malloc(sizeof(char*) * 2);
	if (!tab)
		exit(ERROR_MALLOC);
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			tab[0] = ft_strsub(str, 0, i);
			while (ft_isspace(str[i]))
				i++;
			tab[1] = get_args(&str[i]);
			ft_strdel(&str);
			return (tab);
		}
		i++;
	}
	ft_strdel(&str);
	free(tab);
	return (NULL);
}
