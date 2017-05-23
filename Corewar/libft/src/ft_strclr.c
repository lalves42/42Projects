/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:36:28 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:53:42 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG

# include "libft.h"

void	ft_strclr(char *s)
{
	if (!s)
	{
		ERROR_PARAM("ft_strclr");
		return ;
	}
	while (*s != '\0')
		*s++ = '\0';
}

#else

void	ft_strclr(char *s)
{
	while (*s != '\0')
		*s++ = '\0';
}
#endif
