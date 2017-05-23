/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:36:14 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:42:43 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

char	*ft_strstr(char const *s1, char const *s2)
{
	char const	*ptr_s1;
	char const	*ptr_s2;

	if (!s1 || !s2)
	{
		ERROR_PARAM("ft_strstr");
		return (NULL);
	}
	if (!*s2)
		return ((char *)s1);
	ptr_s1 = s1;
	ptr_s2 = s2;
	while (*s1)
	{
		ptr_s1 = s1;
		ptr_s2 = s2;
		while (*ptr_s2 && *ptr_s2++ == *ptr_s1++)
			;
		if (!*ptr_s2)
			return ((char *)s1);
		s1++;
	}
	if (!*ptr_s2)
		return ((char *)s1);
	return (NULL);
}

#else

char	*ft_strstr(char const *s1, char const *s2)
{
	char const	*ptr_s1;
	char const	*ptr_s2;

	if (!*s2)
		return ((char *)s1);
	ptr_s1 = s1;
	ptr_s2 = s2;
	while (*s1)
	{
		ptr_s1 = s1;
		ptr_s2 = s2;
		while (*ptr_s2 && *ptr_s2 == *ptr_s1)
		{
			ptr_s1++;
			ptr_s2++;
		}
		if (!*ptr_s2)
			return ((char *)s1);
		s1++;
	}
	if (!*ptr_s2)
		return ((char *)s1);
	return (NULL);
}
#endif
