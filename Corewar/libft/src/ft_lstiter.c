/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:48:21 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/06 00:08:02 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
	{
		ERROR_PARAM("ft_lstiter");
		return ;
	}
	f(lst);
	if (lst->next)
		ft_lstiter(lst->next, f);
}

#else

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	f(lst);
	if (lst->next)
		ft_lstiter(lst->next, f);
}
#endif
