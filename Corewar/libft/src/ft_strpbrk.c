/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:55:16 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/01 21:52:42 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

static char		*debug_ft_strpbrk(const char *s1, const char *s2)
{
	int		i;

	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (NULL);
}

char			*ft_strpbrk(const char *s1, const char *s2)
{
	if (!s1 || !s2)
	{
		ERROR_PARAM("ft_strpbrk");
		return (NULL);
	}
	return (debug_ft_strpbrk(s1, s2));
}

#else

char			*ft_strpbrk(const char *s1, const char *s2)
{
	int		i;

	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (NULL);
}
#endif
