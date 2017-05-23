/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:36:01 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:42:25 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**set(char **table, int idx, char *new_str)
{
	int i;

	i = 0;
	table[idx] = new_str;
	if (!table[idx])
	{
		while (i < idx)
			ft_memdel((void **)&table[i++]);
		ft_memdel((void **)&table);
	}
	return (table);
}

static char		**split(char const *s, char c, size_t count)
{
	char	**words_table;
	char	*str;
	int		idx;

	idx = 0;
	while (s[idx] == c)
		s++;
	str = ft_strchr(&s[idx], c);
	if (!str)
	{
		count += (s[0] == '\0') ? 0 : 1;
		if ((words_table = (char **)ft_memalloc(sizeof(char *) * (count + 1))))
		{
			words_table[count] = NULL;
			words_table = set(words_table, count - 1,
								ft_strsub(&s[idx], 0, ft_strlen(&s[idx])));
		}
		return (words_table);
	}
	if ((words_table = split(str, c, count + 1)))
		words_table = set(words_table, count, ft_strsub(&s[idx], 0,
								((uintptr_t)str - (uintptr_t)&s[idx])));
	return (words_table);
}

#ifdef DEBUG

char			**ft_strsplit(char const *s, char c)
{
	if (!s)
	{
		ERROR_PARAM("ft_strsplit");
		return (NULL);
	}
	return (split(s, c, 0));
}

#else

char			**ft_strsplit(char const *s, char c)
{
	return (split(s, c, 0));
}
#endif
