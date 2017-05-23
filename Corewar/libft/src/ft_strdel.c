/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:33:25 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:54:24 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_strdel(char **as)
{
	if (!as)
	{
		ERROR_PARAM("ft_strdel");
		return ;
	}
	if (!*as)
	{
		ERROR_FREE("ft_strdel");
		return ;
	}
	free(*as);
	*as = NULL;
}

#else

void	ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}
#endif
