/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:37:26 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:44:20 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t	i;

	if (!s)
	{
		ERROR_PARAM("ft_memchr");
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		if (((unsigned char const *)s)[i] == (unsigned char)c)
			return ((void *)&(((unsigned char const *)s)[i]));
		i++;
	}
	return (NULL);
}

#else

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char const *)s)[i] == (unsigned char)c)
			return ((void *)&(((unsigned char const *)s)[i]));
		i++;
	}
	return (NULL);
}
#endif
