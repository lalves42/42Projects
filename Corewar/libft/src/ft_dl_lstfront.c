/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:40:03 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:58:41 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

t_dl_list	*ft_dl_lstfront(t_dl_list *lst)
{
	if (!lst)
	{
		ERROR_PARAM("ft_dl_lstfront");
		return (NULL);
	}
	if (lst->prev)
		return (ft_dl_lstfront(lst->prev));
	return (lst);
}

#else

t_dl_list	*ft_dl_lstfront(t_dl_list *lst)
{
	if (lst->prev)
		return (ft_dl_lstfront(lst->prev));
	return (lst);
}
#endif
