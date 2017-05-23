/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:34:22 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:54:46 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG

# include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
	{
		ERROR_PARAM("ft_striter");
		return ;
	}
	while (*s)
		f(s++);
}

#else

void	ft_striter(char *s, void (*f)(char *))
{
	while (*s)
		f(s++);
}
#endif
