/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:35:40 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:56:21 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	if (!s || !f)
	{
		ERROR_PARAM("ft_strmapi");
		return (NULL);
	}
	new_str = ft_strnew(ft_strlen(s));
	if (new_str)
	{
		i = 0;
		while (s[i] != '\0')
		{
			new_str[i] = f(i, s[i]);
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}

#else

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	new_str = ft_strnew(ft_strlen(s));
	if (new_str)
	{
		i = 0;
		while (s[i] != '\0')
		{
			new_str[i] = f(i, s[i]);
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
#endif
