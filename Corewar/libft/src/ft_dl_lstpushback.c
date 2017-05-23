/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstpushback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:31:17 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/06 00:00:45 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_dl_lstpushback(t_dl_list *lst, t_dl_list *new)
{
	t_dl_list	*last;

	if (!lst || !new)
	{
		ERROR_PARAM("ft_dl_lstpushback");
		return ;
	}
	last = ft_dl_lstback(lst);
	last->next = new;
	new->prev = last;
}

#else

void	ft_dl_lstpushback(t_dl_list *lst, t_dl_list *new)
{
	t_dl_list	*last;

	last = ft_dl_lstback(lst);
	last->next = new;
	new->prev = last;
}
#endif
