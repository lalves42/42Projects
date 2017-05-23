/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 21:54:08 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/03 03:33:27 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*str_new;
	char	*ptr;
	int		i;

	i = 0;
	if (!s1 || !s2)
	{
		ERROR_PARAM("ft_strnjoin");
		return (NULL);
	}
	str_new = ft_strnew(ft_strlen(s1) + n);
	if (str_new)
	{
		ptr = str_new;
		while (*s1)
			*ptr++ = *s1++;
		while (*s2 && i < n)
		{
			*ptr++ = *s2++;
			i++;
		}
		*ptr++ = '\0';
	}
	return (str_new);
}

#else

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*str_new;
	char	*ptr;
	int		i;

	i = 0;
	str_new = ft_strnew(ft_strlen(s1) + n);
	if (str_new)
	{
		ptr = str_new;
		while (*s1)
			*ptr++ = *s1++;
		while (*s2 && i < n)
		{
			*ptr++ = *s2++;
			i++;
		}
		*ptr++ = '\0';
	}
	return (str_new);
}
#endif
