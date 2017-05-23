/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstpushfront.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:25:19 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/06 00:14:28 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_dl_lstpushfront(t_dl_list **alst, t_dl_list *new)
{
	t_dl_list	*first;

	if (!alst || !new || !*alst)
	{
		ERROR_PARAM("ft_dl_lstpushfront");
		return ;
	}
	first = ft_dl_lstfront(*alst);
	new->next = first;
	first->prev = new;
	*alst = new;
}

#else

void	ft_dl_lstpushfront(t_dl_list **alst, t_dl_list *new)
{
	t_dl_list	*first;

	first = ft_dl_lstfront(*alst);
	new->next = first;
	first->prev = new;
	*alst = new;
}
#endif
