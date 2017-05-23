/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:37:29 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 19:58:45 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t	i;

	if (!dst || !src)
	{
		ERROR_PARAM("ft_memccpy");
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char const *)src)[i];
		if (((unsigned char const *)src)[i] == (unsigned char)c)
			return (&((unsigned char *)dst)[i + 1]);
		i++;
	}
	return (NULL);
}

#else

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char const *)src)[i];
		if (((unsigned char const *)src)[i] == (unsigned char)c)
			return (&((unsigned char *)dst)[i + 1]);
		i++;
	}
	return (NULL);
}
#endif
