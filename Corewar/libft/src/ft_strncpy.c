/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:35:49 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:56:53 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

char	*ft_strncpy(char *dst, char const *src, size_t n)
{
	size_t	i;
	size_t	max;

	if (!dst || !src)
	{
		ERROR_PARAM("ft_strncpy");
		return (NULL);
	}
	max = ft_strlen(src);
	i = 0;
	while (i < n)
	{
		if (i < max)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}

#else

char	*ft_strncpy(char *dst, char const *src, size_t n)
{
	size_t	i;
	size_t	max;

	max = ft_strlen(src);
	i = 0;
	while (i < n)
	{
		if (i < max)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
#endif
