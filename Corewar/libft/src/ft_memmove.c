/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:37:16 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:45:21 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

static void		*move_memory(void *dst, void const *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;
	size_t		i;

	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	if ((unsigned long)ptr_dst < (unsigned long)ptr_src)
	{
		i = 0;
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			ptr_dst[i] = ptr_src[i];
		ptr_dst[0] = ptr_src[0];
	}
	return (dst);
}

void			*ft_memmove(void *dst, void const *src, size_t len)
{
	if (!dst || !src)
	{
		ERROR_PARAM("ft_memmove");
		return (NULL);
	}
	if (len == 0 || dst == src)
		return (dst);
	return (move_memory(dst, src, len));
}

#else

void			*ft_memmove(void *dst, void const *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;
	size_t		i;

	if (len == 0 || dst == src)
		return (dst);
	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	if (ptr_dst - ptr_src < 0)
	{
		i = 0;
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			ptr_dst[i] = ptr_src[i];
		ptr_dst[0] = ptr_src[0];
	}
	return (dst);
}
#endif
