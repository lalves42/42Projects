/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:34:31 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/08 16:25:58 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

static size_t	cat(char *dst, char const *src, size_t size)
{
	char	*ptr;
	size_t	total_size;
	size_t	src_len;
	size_t	max;
	size_t	i;

	src_len = ft_strlen(src);
	ptr = dst;
	i = 0;
	while (*ptr)
	{
		if (i++ >= size)
			break ;
		ptr++;
	}
	if (i >= size)
		return (size + src_len);
	i = 0;
	total_size = ft_strlen(dst);
	max = size - total_size - (1 * sizeof(char));
	total_size += src_len;
	while (*src && i++ < max)
		*ptr++ = *src++;
	*ptr = '\0';
	return (total_size);
}

size_t			ft_strlcat(char *dst, char const *src, size_t size)
{
	if (!dst || !src)
	{
		ERROR_PARAM("ft_strlcat");
		return (0);
	}
	return (cat(dst, src, size));
}

#else

size_t			ft_strlcat(char *dst, char const *src, size_t size)
{
	char	*ptr;
	size_t	total_size;
	size_t	src_len;
	size_t	max;
	size_t	i;

	src_len = ft_strlen(src);
	ptr = dst;
	i = 0;
	while (*ptr)
	{
		if (i++ >= size)
			break ;
		ptr++;
	}
	if (i >= size)
		return (size + src_len);
	i = 0;
	total_size = ft_strlen(dst);
	max = size - total_size - (1 * sizeof(char));
	total_size += src_len;
	while (*src && i++ < max)
		*ptr++ = *src++;
	*ptr = '\0';
	return (total_size);
}
#endif
