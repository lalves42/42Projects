/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:30:28 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/06 00:16:23 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !del)
	{
		ERROR_PARAM("ft_lstdelone");
		return ;
	}
	if (!*alst)
	{
		ERROR_FREE("ft_lstdelone");
		return ;
	}
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}

#else

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
#endif
