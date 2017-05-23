/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:36:31 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 17:04:54 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

char	*ft_strchr(char const *s, int c)
{
	if (!s)
	{
		ERROR_PARAM("ft_strchr");
		return (NULL);
	}
	if ((char)c == '\0')
		return (&((char *)s)[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

#else

char	*ft_strchr(char const *s, int c)
{
	if ((char)c == '\0')
		return (&((char *)s)[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
#endif
