/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:16:06 by lalves            #+#    #+#             */
/*   Updated: 2016/10/14 17:15:25 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_str_length(char const *s, size_t i, char c)
{
	size_t len;

	len = 1;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static size_t	ft_tab_length(char const *s, char c)
{
	size_t i;
	size_t len;

	i = 0;
	len = 1;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			len++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (len);
}

static char		**ft_strsplit_helper(char *s, char c, size_t i, char **ret)
{
	size_t index;
	size_t j;

	index = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			ret[index] = (char*)malloc(sizeof(char) * ft_str_length(s, i, c));
			if (ret[index] == NULL)
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				ret[index][j++] = s[i++];
			ret[index][j] = '\0';
			j = 0;
			index++;
		}
	}
	ret[index] = NULL;
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	size_t	i;

	i = 0;
	ret = (char**)malloc(sizeof(char*) * ft_tab_length(s, c));
	if (ret == NULL)
		return (NULL);
	return (ft_strsplit_helper((char*)s, c, i, ret));
}
