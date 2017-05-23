/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:36:22 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:54:02 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG

# include "libft.h"

char	*ft_strcpy(char *dst, char const *src)
{
	char *ptr;

	if (!dst | !src)
	{
		ERROR_PARAM("ft_strcpy");
		return (NULL);
	}
	ptr = dst;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dst);
}

#else

char	*ft_strcpy(char *dst, char const *src)
{
	char *ptr;

	ptr = dst;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dst);
}
#endif
