/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:37:22 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/09 13:02:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char		*p_dst;
	const char	*p_src;

	if (!dst || !src)
	{
		ERROR_PARAM("ft_memcpy");
		return (NULL);
	}
	p_dst = dst;
	p_src = src;
	while (n--)
		*p_dst++ = *p_src++;
	return (dst);
}

#else

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char		*p_dst;
	const char	*p_src;

	p_dst = dst;
	p_src = src;
	while (n--)
		*p_dst++ = *p_src++;
	return (dst);
}
#endif
