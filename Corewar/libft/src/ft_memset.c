/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:33:45 by tdefresn          #+#    #+#             */
/*   Updated: 2016/11/09 09:13:15 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	unsigned char	uc;

	if (!b)
	{
		ERROR_PARAM("ft_memset");
		return (NULL);
	}
	uc = (unsigned char)c;
	ptr = (char *)b;
	while (len--)
		*ptr++ = uc;
	return (b);
}

#else

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	unsigned char	uc;

	uc = (unsigned char)c;
	ptr = (char *)b;
	while (len--)
		*ptr++ = uc;
	return (b);
}
#endif
