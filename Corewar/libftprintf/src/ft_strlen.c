/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:40:20 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/03 03:32:06 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

#ifdef DEBUG

size_t	ft_strlen(char const *s)
{
	size_t	i;

	if (!s)
	{
		ft_printf("ft_strlen: param error");
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
