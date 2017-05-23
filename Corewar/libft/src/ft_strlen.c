/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:35:30 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/01 21:47:36 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

size_t	ft_strlen(char const *s)
{
	size_t	i;

	if (!s)
	{
		ERROR_PARAM("ft_strlen");
		return (0);
	}
	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}

#else

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}
#endif
