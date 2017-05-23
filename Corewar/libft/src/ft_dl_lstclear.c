/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:45:50 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:58:29 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_dl_lstclear(t_dl_list **alst)
{
	if (!alst)
	{
		ERROR_PARAM("ft_dl_lstclear");
		return ;
	}
	if (!*alst)
	{
		ERROR_FREE("ft_dl_lstclear");
		return ;
	}
	if ((*alst)->next)
		ft_dl_lstclear(&(*alst)->next);
	ft_memdel((void **)alst);
}

#else

void	ft_dl_lstclear(t_dl_list **alst)
{
	if ((*alst)->next)
		ft_dl_lstclear(&(*alst)->next);
	ft_memdel((void **)alst);
}
#endif
