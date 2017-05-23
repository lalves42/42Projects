/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:42:36 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/05 23:58:08 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

t_dl_list	*ft_dl_lstback(t_dl_list *lst)
{
	if (!lst)
	{
		ERROR_PARAM("ft_dl_lstback");
		return (NULL);
	}
	if (lst->next)
		return (ft_dl_lstback(lst->next));
	return (lst);
}

#else

t_dl_list	*ft_dl_lstback(t_dl_list *lst)
{
	if (lst->next)
		return (ft_dl_lstback(lst->next));
	return (lst);
}
#endif
