/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:37:19 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:45:03 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_memdel(void **ap)
{
	if (!ap)
	{
		ERROR_PARAM("ft_memdel");
		return ;
	}
	if (!*ap)
	{
		ERROR_FREE("ft_memdel");
		return ;
	}
	free(*ap);
	*ap = NULL;
}

#else

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
#endif
